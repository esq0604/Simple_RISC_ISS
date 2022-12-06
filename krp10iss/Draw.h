#pragma once

class Instruction;
class Draw
{
private:
	const int COL = 8;
	const int ROW = 4;

public:
	Draw(Instruction* instruction);
	void DrawMainMenu() const;
	void DrawRegState() const;
	void DrawInstByte() const;
	void DrawPC() const;
private:

	Instruction* mInstruction;
};