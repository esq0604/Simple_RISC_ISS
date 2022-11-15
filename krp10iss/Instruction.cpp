#include"instruction.h"

Instruction::Instruction()
{

}

Instruction::Instruction(std::string bitData)
{
	//imm 
	for (int i = 0; i < 17; i++)
	{
		mbitData[i]=bitData[i];
	}

	//rb 
	for (int i = 17; i < 22; i++)
	{
		mbitData[i] = bitData[i];
	}

	for (int i = 22; i < 27; i++)
	{
		mbitData[i] = bitData[i];
	}

	for (int i = 27; i < 32; i++)
	{
		mbitData[i] = mbitData[i];
	}
}

Instruction::~Instruction()
{

}
