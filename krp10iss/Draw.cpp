#include "Draw.h"
#include "Instruction.h"
#include "DataPreProcessing.h"
#include<iostream>
#include<iomanip>


Draw::Draw() 
{

}

void Draw::DrawMainMenu() const
{
	std::cout << "KPP IX Instruction Set Simulator" << std::endl;
	std::cout << "Request:" << std::endl;
	std::cout << ">> ";
}

void Draw::DrawRegState() const
{
	vector<int> vec = mInstruction->GetRegState();

	for (int i = 0; i < COL; i++)
	{
		for (int j = 0; j < ROW; j++)
		{
			cout << "reg[" << (i * ROW) + j << "]: " << vec[(i * ROW) + j] << '\t';
		}
		cout << endl;
	}
}

void Draw::DrawInstByte() const
{
	string data = mDataPreProcessing->GetInstData();
	int pc = mInstruction->GetPC()-1;
	cout << "Inst :";
	for(int i=3; i>=0; i--)
	std::cout << hex << int(data[(pc*4)+i]) <<dec;
	cout << endl;
}

void Draw::DrawPC() const
{
	cout  << "PC :"<< setw(8) << setfill('0') <<hex << (mInstruction->GetPC()-1)*4 <<dec <<endl;
}

void Draw::SetInstruction(Instruction* inst)
{
	mInstruction = inst;
}

void Draw::SetDatePreProcessing(DataPreProcessing* datapreprocessing)
{
	mDataPreProcessing = datapreprocessing;
}


