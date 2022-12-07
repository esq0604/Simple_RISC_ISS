#pragma once

class Instruction;
class DataPreProcessing;
class Draw
{
private:
	const int COL = 8;
	const int ROW = 4;

public:
	Draw();
	void DrawMainMenu() const;
	void DrawRegState() const;
	void DrawInstByte() const;
	void DrawPC() const;
	
	void SetInstruction(Instruction* inst);
	void SetDatePreProcessing(DataPreProcessing* datapreprocessing);
private:

	Instruction* mInstruction;
	DataPreProcessing* mDataPreProcessing;
};