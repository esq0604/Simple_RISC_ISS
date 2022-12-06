#pragma once

#include"instruction.h"
#include"DataPreProcessing.h" 
#include<iostream>
#include<typeinfo>

extern unsigned char buffer[4 * 10];

Instruction::Instruction(string instSet[], DataPreProcessing*& dataPreProceccing) :
	mPC(0),
	mDataPreProcessing(dataPreProceccing)
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


	if (mOpcode[mPC] == "00000") //ADDI
	{
		mReg[mDataPreProcessing->ChangeBinToDec(mRa[mPC])] = mReg[mDataPreProcessing->ChangeBinToDec(mRb[mPC])] + mDataPreProcessing->ChangeBinToDec(mImm[mPC]);
	}

	else if (mOpcode[mPC] == "00010") //ORI
	{
		mReg[mDataPreProcessing->ChangeBinToDec(mRa[mPC])] = mReg[mDataPreProcessing->ChangeBinToDec(mRb[mPC])] | mDataPreProcessing->ChangeBinToDec(mImm[mPC]);
		mAddressAndVal.push_back(make_pair(&mReg[mDataPreProcessing->ChangeBinToDec(mRa[mPC])], mReg[mDataPreProcessing->ChangeBinToDec(mRa[mPC])]));
	}
	else if (mOpcode[mPC] == "00110") //MOVEI
	{
		mReg[mDataPreProcessing->ChangeBinToDec(mRa[mPC])] = mDataPreProcessing->ChangeBinToDec(mImm[mPC]);
	}
	else if (mOpcode[mPC] == "00100") //ANDI
	{
		mReg[mDataPreProcessing->ChangeBinToDec(mRa[mPC])] = mReg[mDataPreProcessing->ChangeBinToDec(mRb[mPC])] & mDataPreProcessing->ChangeBinToDec(mImm[mPC]);
	}
	else if (mOpcode[mPC] == "01010") //NOT
	{
		mReg[mDataPreProcessing->ChangeBinToDec(mRa[mPC])] = ~mReg[mDataPreProcessing->ChangeBinToDec(mRc[mPC])];
	}
	else if (mOpcode[mPC] == "01000") //ADD
	{
		mReg[mDataPreProcessing->ChangeBinToDec(mRa[mPC])] = mReg[mDataPreProcessing->ChangeBinToDec(mRb[mPC])] + mReg[mDataPreProcessing->ChangeBinToDec(mRc[mPC])];
	}
	else if (mOpcode[mPC] == "01001") //SUB
	{
		mReg[mDataPreProcessing->ChangeBinToDec(mRa[mPC])] = mReg[mDataPreProcessing->ChangeBinToDec(mRb[mPC])] - mReg[mDataPreProcessing->ChangeBinToDec(mRc[mPC])];
	}
	else if (mOpcode[mPC] == "01011") //NEG
	{
		mReg[mDataPreProcessing->ChangeBinToDec(mRa[mPC])] = -mReg[mDataPreProcessing->ChangeBinToDec(mRc[mPC])];
	}
	else if (mOpcode[mPC] == "01101") //AND
	{
		mReg[mDataPreProcessing->ChangeBinToDec(mRa[mPC])] = mReg[mDataPreProcessing->ChangeBinToDec(mRb[mPC])] & mReg[mDataPreProcessing->ChangeBinToDec(mRc[mPC])];
	}
	else if (mOpcode[mPC] == "01110") //XOR
	{
		mReg[mDataPreProcessing->ChangeBinToDec(mRa[mPC])] = mReg[mDataPreProcessing->ChangeBinToDec(mRb[mPC])] ^ mReg[mDataPreProcessing->ChangeBinToDec(mRc[mPC])];
	}
	else if (mOpcode[mPC] == "01111") //ASR
	{
		//sign-extension


	}
	else if (mOpcode[mPC] == "10000")//LSR
	{
		//no sign-extensio
		if (mI[mPC] == "0")
			mReg[mDataPreProcessing->ChangeBinToDec(mRa[mPC])] = mReg[mDataPreProcessing->ChangeBinToDec(mRb[mPC])] >> mDataPreProcessing->ChangeBinToDec(mShamt[mPC]);
		else
			mReg[mDataPreProcessing->ChangeBinToDec(mRa[mPC])] = mReg[mDataPreProcessing->ChangeBinToDec(mRb[mPC])] >> mReg[mDataPreProcessing->ChangeBinToDec(mRc[mPC])];
	}
	else if (mOpcode[mPC] == "10001") //SHL
	{
		if (mI[mPC] == "0")
			mReg[mDataPreProcessing->ChangeBinToDec(mRa[mPC])] = mReg[mDataPreProcessing->ChangeBinToDec(mRb[mPC])] << mDataPreProcessing->ChangeBinToDec(mShamt[mPC]);
		else
			mReg[mDataPreProcessing->ChangeBinToDec(mRa[mPC])] = mReg[mDataPreProcessing->ChangeBinToDec(mRb[mPC])] << mReg[mDataPreProcessing->ChangeBinToDec(mRc[mPC])];
	}
	else if (mOpcode[mPC] == "10010") //ROR
	{

		if (mI[mPC] == "0")
			mReg[mDataPreProcessing->ChangeBinToDec(mRa[mPC])] =
			(mReg[mDataPreProcessing->ChangeBinToDec(mRb[mPC])] >> mDataPreProcessing->ChangeBinToDec(mShamt[mPC])) | (mReg[mDataPreProcessing->ChangeBinToDec(mRb[mPC])] << (INT_BIT - mDataPreProcessing->ChangeBinToDec(mShamt[mPC])));
		else
			mReg[mDataPreProcessing->ChangeBinToDec(mRa[mPC])] =
			(mReg[mDataPreProcessing->ChangeBinToDec(mRb[mPC])] >> mReg[mDataPreProcessing->ChangeBinToDec(mRc[mPC])]) | (mReg[mDataPreProcessing->ChangeBinToDec(mRb[mPC])] << (INT_BIT - mReg[mDataPreProcessing->ChangeBinToDec(mRc[mPC])]));

	}
	else if (mOpcode[mPC] == "10011") //BR
	{
		if (mCond[mPC] == "000") // Never
		{

		}
		else if (mCond[mPC] == "001") //Always
		{
			mPC = mReg[mDataPreProcessing->ChangeBinToDec(mRb[mPC])];
		}
		else if (mCond[mPC] == "010" && mReg[mDataPreProcessing->ChangeBinToDec(mRc[mPC])] == 0) //Zero 
		{
			mPC = mReg[mDataPreProcessing->ChangeBinToDec(mRb[mPC])];
		}
		else if (mCond[mPC] == "011" && mReg[mDataPreProcessing->ChangeBinToDec(mRc[mPC])] != 0) //NonZero
		{
			mPC = mReg[mDataPreProcessing->ChangeBinToDec(mRb[mPC])];
		}
		else if (mCond[mPC] == "100" && mReg[mDataPreProcessing->ChangeBinToDec(mRc[mPC])] >= 0) //Plus
		{

			mPC = mReg[mDataPreProcessing->ChangeBinToDec(mRb[mPC])];
		}
		else if (mCond[mPC] == "101" && mReg[mDataPreProcessing->ChangeBinToDec(mRc[mPC])] < 0) //Minus
		{
			mPC = mReg[mDataPreProcessing->ChangeBinToDec(mRb[mPC])];
		}

	}
	else if (mOpcode[mPC] == "10100") //BRL
	{
		mReg[mDataPreProcessing->ChangeBinToDec(mRa[mPC])] = mPC;

		if (mCond[mPC] == "000") // Never
		{

		}
		else if (mCond[mPC] == "001") //Always
		{
			mPC = mReg[mDataPreProcessing->ChangeBinToDec(mRa[mPC])];
		}
		else if (mCond[mPC] == "010" && mReg[mDataPreProcessing->ChangeBinToDec(mRc[mPC])] == 0) //Zero 
		{
			mPC = mReg[mDataPreProcessing->ChangeBinToDec(mRa[mPC])];
		}
		else if (mCond[mPC] == "011" && mReg[mDataPreProcessing->ChangeBinToDec(mRc[mPC])] != 0) //NonZero
		{
			mPC = mReg[mDataPreProcessing->ChangeBinToDec(mRa[mPC])];
		}
		else if (mCond[mPC] == "100" && mReg[mDataPreProcessing->ChangeBinToDec(mRc[mPC])] >= 0) //Plus
		{
			mPC = mReg[mDataPreProcessing->ChangeBinToDec(mRb[mPC])];
		}
		else if (mCond[mPC] == "101" && mReg[mDataPreProcessing->ChangeBinToDec(mRc[mPC])] < 0) //Minus
		{
			mPC = mReg[mDataPreProcessing->ChangeBinToDec(mRb[mPC])];
		}
	}
	else if (mOpcode[mPC] == "10101") //J
	{
		//TODO : signExt
		mPC += mDataPreProcessing->ChangeBinToDec(mImm22[mPC]);
	}
	else if (mOpcode[mPC] == "10110") //JL
	{
		mReg[mDataPreProcessing->ChangeBinToDec(mRa[mPC])] = mPC;

		mPC += mDataPreProcessing->ChangeBinToDec(mImm22[mPC]);
	}
	else if (mOpcode[mPC] == "10111") //LD
	{
		if (mRb[mPC] == "11111")
		{
			mReg[mDataPreProcessing->ChangeBinToDec(mRa[mPC])] = buffer[mDataPreProcessing->ChangeBinToDec(mImm[mPC])];
		}

		mReg[mDataPreProcessing->ChangeBinToDec(mRa[mPC])] =
			buffer[mDataPreProcessing->ChangeBinToDec(mImm[mPC]) + mReg[mDataPreProcessing->ChangeBinToDec(mRb[mPC])]];
	}
	else if (mOpcode[mPC] == "11000") //LDR
	{
		mReg[mDataPreProcessing->ChangeBinToDec(mRa[mPC])] = buffer[mPC + mDataPreProcessing->ChangeBinToDec(mImm[mPC])];
	}
	else if (mOpcode[mPC] == "11001") //ST
	{
		if (mRb[mPC] == "11111")
		{
			buffer[mDataPreProcessing->ChangeBinToDec(mImm[mPC])] = mReg[mDataPreProcessing->ChangeBinToDec(mRa[mPC])];
		}
		buffer[mDataPreProcessing->ChangeBinToDec(mRb[mPC]) + mDataPreProcessing->ChangeBinToDec(mImm[mPC])] =
			mReg[mDataPreProcessing->ChangeBinToDec(mRa[mPC])];
	}
	else if (mOpcode[mPC] == "11010") //STR
	{
		buffer[mDataPreProcessing->ChangeBinToDec(mRb[mPC]) + mDataPreProcessing->ChangeBinToDec(mImm22[mPC])] =
			mReg[mDataPreProcessing->ChangeBinToDec(mRa[mPC])];

	}
	else if (mOpcode[mPC] == "11011") //LEA
	{
		mReg[mDataPreProcessing->ChangeBinToDec(mRa[mPC])] = mPC + mDataPreProcessing->ChangeBinToDec(mImm22[mPC]);

	}
	else if (mOpcode[mPC] == "11100") //MSN
	{
		mReg[mDataPreProcessing->ChangeBinToDec(mRa[mPC])] = 20181393;
	}
	//인터럽트는 구현 X 
	else
	{
		cout << "Other Operator" << endl;
	}

	++mPC;
}

void Instruction::SetCommand(const char& command)
{
	mCommand = command;
}


const vector<int>& Instruction::GetRegState() const
{
	return mReg;
}

string Instruction::GetByte() const
{
	return mByte[mPC];
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





