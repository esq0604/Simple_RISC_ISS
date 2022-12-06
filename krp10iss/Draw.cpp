#include "Draw.h"
#include "Instruction.h"
#include<iostream>
#include<iomanip>


Draw::Draw(Instruction* instruction) :
	mInstruction(instruction)
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
	cout << "Inst:" << mInstruction->GetByte() << endl;
}

void Draw::DrawPC() const
{
	cout << "PC :" << mInstruction->GetPC() << endl;
}
