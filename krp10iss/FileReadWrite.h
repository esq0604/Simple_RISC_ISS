#pragma once
#include<string>

class FileReadWrite
{
public:
	FileReadWrite();
	FileReadWrite(const std::string inputFile, const std::string outputFile);
	
	void ReadFile();
	void WriteFile() const;

	std::string GetBuffer() const;
	int GetInstructinNum() const;
public:
	unsigned int mResultBufferIdx = 0;
	int* mResultBuffer;

private:
	unsigned int INST_NUM=0; //���� ���� �� ����
	std::string mReadFileName;
	std::string mOutFileName;
	std::string mBuffer; //�޾ƿ� �� 

};
