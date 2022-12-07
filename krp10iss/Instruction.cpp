#pragma once
#include<iostream>
#include<typeinfo>

#include"instruction.h"
#include"FileReadWrite.h"
#include"DataPreProcessing.h"

extern unsigned char buffer[4 * 10];

Instruction::Instruction(vector<string> instSet) :
	mPC(0)
{
	mReg.reserve(REG_SIZE);
	mDataPreProcessing = new DataPreProcessing;

	for (int i = 0; i < INST_NUM; i++)
	{
		mInstSet[i] = instSet[i];
	}

	//InstSet Initialize in Little Endian 
	for (int i = 0; i < INST_NUM; i++)
	{
		for (int j = 15; j < 32; j++)
		{
			mImm[i] += instSet[i][j];
		}
		for (int j = 10; j < 15; j++)
		{
			mRb[i] += instSet[i][j];
		}
		for (int j = 5; j < 10; j++)
		{
			mRa[i] += instSet[i][j];
		}
		for (int j = 0; j < 5; j++)
		{
			mOpcode[i] += instSet[i][j];
		}
		for (int j = 15; j < 20; j++)
		{
			mRc[i] += instSet[i][j];
		}
		for (int j = 27; j < 32; j++)
		{
			mShamt[i] += instSet[i][j];
		}
		for (int j = 29; j < 32; j++)
		{
			mCond[i] += instSet[i][j];
		}
		for (int j = 10; j < 32; j++)
		{
			mImm22[i] += instSet[i][j];
		}
		mI[i] = instSet[i][26];
	}
	for (int i = 0; i < REG_SIZE; i++)
	{
		mReg.push_back(0);
	}


}

Instruction::~Instruction()
{

}

void Instruction::OperInstSet()
{
	int imm17 = mDataPreProcessing->ChangeBinToDec(mImm[mPC]);
	int imm22 = mDataPreProcessing->ChangeBinToDec(mImm22[mPC]);
	int rb = mDataPreProcessing->ChangeBinToDec(mRb[mPC]);
	int ra = mDataPreProcessing->ChangeBinToDec(mRa[mPC]);
	int rc = mDataPreProcessing->ChangeBinToDec(mRc[mPC]);
	int shamt = mDataPreProcessing->ChangeBinToDec(mShamt[mPC]);

	if (mOpcode[mPC] == "00000") //ADDI
	{
		mFileReadWrite->mResultBuffer[mFileReadWrite->mResultBufferIdx++] = mReg[ra] = mReg[rb] + imm17;
	}

	else if (mOpcode[mPC] == "00010") //ORI
	{
		mFileReadWrite->mResultBuffer[mFileReadWrite->mResultBufferIdx++] = mReg[ra] = mReg[rb] | imm17;
	}
	else if (mOpcode[mPC] == "00110") //MOVEI
	{
		mFileReadWrite->mResultBuffer[mFileReadWrite->mResultBufferIdx++] = mReg[ra] = imm17;
	}
	else if (mOpcode[mPC] == "00100") //ANDI
	{
		mFileReadWrite->mResultBuffer[mFileReadWrite->mResultBufferIdx++] = mReg[ra] = mReg[rb] & imm17;
	}
	else if (mOpcode[mPC] == "01010") //NOT
	{
		mFileReadWrite->mResultBuffer[mFileReadWrite->mResultBufferIdx++] = mReg[ra] = ~mReg[rc];
	}
	else if (mOpcode[mPC] == "01000") //ADD
	{
		mFileReadWrite->mResultBuffer[mFileReadWrite->mResultBufferIdx++] = mReg[ra] = mReg[rb] + mReg[rc];
	}
	else if (mOpcode[mPC] == "01001") //SUB
	{
		mFileReadWrite->mResultBuffer[mFileReadWrite->mResultBufferIdx++] = mReg[ra] = mReg[rb] - mReg[rc];
	}
	else if (mOpcode[mPC] == "01011") //NEG
	{
		mFileReadWrite->mResultBuffer[mFileReadWrite->mResultBufferIdx++] = mReg[ra] = -mReg[rc];
	}
	else if (mOpcode[mPC] == "01101") //AND
	{
		mFileReadWrite->mResultBuffer[mFileReadWrite->mResultBufferIdx++] = mReg[ra] = mReg[rb] & mReg[rc];
	}
	else if (mOpcode[mPC] == "01110") //XOR
	{
		mFileReadWrite->mResultBuffer[mFileReadWrite->mResultBufferIdx++] = mReg[ra] = mReg[rb] ^ mReg[rc];
	}
	else if (mOpcode[mPC] == "01111") //ASR
	{
		//sign-extension
		if (mI[mPC] == "0")
			mFileReadWrite->mResultBuffer[mFileReadWrite->mResultBufferIdx++] = mReg[ra] = mReg[rb] >> shamt;
		else
			mFileReadWrite->mResultBuffer[mFileReadWrite->mResultBufferIdx++] = mReg[ra] = mReg[rb] >> mReg[rc];
	}
	else if (mOpcode[mPC] == "10000")//LSR
	{
		//no sign-extensio
		if (mI[mPC] == "0")
			mFileReadWrite->mResultBuffer[mFileReadWrite->mResultBufferIdx++] = mReg[ra] = mReg[rb] >> shamt;
		else
			mFileReadWrite->mResultBuffer[mFileReadWrite->mResultBufferIdx++] = mReg[ra] = mReg[rb] >> mReg[rc];
	}
	else if (mOpcode[mPC] == "10001") //SHL
	{
		if (mI[mPC] == "0")
			mFileReadWrite->mResultBuffer[mFileReadWrite->mResultBufferIdx++] = mReg[ra] = mReg[rb] << shamt;
		else
			mFileReadWrite->mResultBuffer[mFileReadWrite->mResultBufferIdx++] = mReg[ra] = mReg[rb] << mReg[rc];
	}
	else if (mOpcode[mPC] == "10010") //ROR
	{

		if (mI[mPC] == "0")
			mFileReadWrite->mResultBuffer[mFileReadWrite->mResultBufferIdx++] = mReg[ra] = (mReg[rb] >> shamt) | (mReg[rb] << (INT_BIT - shamt));
		else
			mFileReadWrite->mResultBuffer[mFileReadWrite->mResultBufferIdx++] = mReg[ra] = (mReg[rb] >> mReg[rc]) | (mReg[rb] << (INT_BIT - mReg[rc]));

	}
	else if (mOpcode[mPC] == "10011") //BR
	{
		if (mCond[mPC] == "000") // Never
		{

		}
		else if (mCond[mPC] == "001") //Always
		{
			mPC = mReg[rb];
		}
		else if (mCond[mPC] == "010" && mReg[rc] == 0) //Zero 
		{
			mPC = mReg[rb];
		}
		else if (mCond[mPC] == "011" && mReg[rc] != 0) //NonZero
		{
			mPC = mReg[rb];
		}
		else if (mCond[mPC] == "100" && mReg[rc] >= 0) //Plus
		{

			mPC = mReg[rb];
		}
		else if (mCond[mPC] == "101" && mReg[rc] < 0) //Minus
		{
			mPC = mReg[rb];
		}

	}
	else if (mOpcode[mPC] == "10100") //BRL
	{
		mReg[ra] = mPC;

		if (mCond[mPC] == "000") // Never
		{

		}
		else if (mCond[mPC] == "001") //Always
		{
			mPC = mReg[ra];
		}
		else if (mCond[mPC] == "010" && mReg[rc] == 0) //Zero 
		{
			mPC = mReg[ra];
		}
		else if (mCond[mPC] == "011" && mReg[rc] != 0) //NonZero
		{
			mPC = mReg[ra];
		}
		else if (mCond[mPC] == "100" && mReg[rc] >= 0) //Plus
		{
			mPC = mReg[rb];
		}
		else if (mCond[mPC] == "101" && mReg[rc] < 0) //Minus
		{
			mPC = mReg[rb];
		}
	}
	else if (mOpcode[mPC] == "10101") //J
	{
		//TODO : signExt
		mPC += imm22;
	}
	else if (mOpcode[mPC] == "10110") //JL
	{
		mReg[ra] = mPC;

		mPC += imm22;
	}
	else if (mOpcode[mPC] == "10111") //LD
	{
		if (mRb[mPC] == "11111")
		{
			mFileReadWrite->mResultBuffer[mFileReadWrite->mResultBufferIdx++] = mReg[ra] = mFileReadWrite->mResultBuffer[imm17];
		}

		mFileReadWrite->mResultBuffer[mFileReadWrite->mResultBufferIdx++] = mReg[ra] = mFileReadWrite->mResultBuffer[imm17 + mReg[rb]];
	}
	else if (mOpcode[mPC] == "11000") //LDR
	{
		mFileReadWrite->mResultBuffer[mFileReadWrite->mResultBufferIdx++] = mReg[ra] = mFileReadWrite->mResultBuffer[mPC + imm17];
	}
	else if (mOpcode[mPC] == "11001") //ST
	{
		if (mRb[mPC] == "11111")
		{
			mFileReadWrite->mResultBuffer[imm17] = mReg[ra];
		}
		mFileReadWrite->mResultBuffer[rb + imm17] = mReg[ra];
	}
	else if (mOpcode[mPC] == "11010") //STR
	{
		mFileReadWrite->mResultBuffer[rb + imm22] = mReg[ra];

	}
	else if (mOpcode[mPC] == "11011") //LEA
	{
		mFileReadWrite->mResultBuffer[mFileReadWrite->mResultBufferIdx++] = mReg[ra] = mPC + imm22;

	}
	else if (mOpcode[mPC] == "11100") //MSN
	{
		mFileReadWrite->mResultBuffer[mFileReadWrite->mResultBufferIdx++] = mReg[ra] = 20181393;
	}
	//인터럽트는 구현 X 
	else
	{
		cout << "other opcode || not exist opcode" << endl;
	}

	++mPC;
}

void Instruction::SetCommand(const char& command)
{
	mCommand = command;
}

void Instruction::SetDataPreProcessing(DataPreProcessing*& dataPreProcessing)
{
	mDataPreProcessing = dataPreProcessing;
}

void Instruction::SetFileReadWrite(FileReadWrite*& fileReadWrite)
{
	mFileReadWrite = fileReadWrite;
}


const vector<int>& Instruction::GetRegState() const
{
	return mReg;
}



void Instruction::GetDataAddress() const
{

}

const int Instruction::GetPC() const
{
	return mPC;
}

const char Instruction::GetCommand() const
{
	return mCommand;
}





