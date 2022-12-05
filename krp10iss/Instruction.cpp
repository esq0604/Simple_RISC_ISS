#pragma once

#include"instruction.h"
#include"DataPreProcessing.h"

#include<iostream>


Instruction::Instruction(string instSet[]) :mPC(0)
{
	for (int i = 0; i < 10; i++)
	{
		mInstSet[i] = instSet[i];
	}

	//InstSet Initialize
	for (int i = 0; i < 10; i++)
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
			mOper[i] += instSet[i][j];
		}
		
	}
	mDataPreProcessing = new DataPreProcessing;

}

Instruction::~Instruction()
{
	
}

void Instruction::OperInstSet()
{
	cout << "Cur PC :" << mPC << endl;
	cout << "Cur Oper : " << mOper[mPC] << endl;
	cout << "Cur Imm : " <<mDataPreProcessing->ChangeBinToDec( mImm[mPC]) << endl;
	cout << "Cur Rb : " << mRb[mPC] << endl;
	cout <<"Cur Ra :" <<mRa[mPC]<<endl;
	if (mOper[mPC] == "00000")
	{
		
	}

	else if (mOper[mPC] == "00010")
	{
		
	}
	else
	{
		cout << "Other Operator" << endl;
	}
	//ra = rb + imm17 

	++mPC;
}

void Instruction::SetCommand(const char& command)
{
	mCommand = command;
}

