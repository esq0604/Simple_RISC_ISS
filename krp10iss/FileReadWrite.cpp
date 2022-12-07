#include "FileReadWrite.h"
#include <iostream>
#include <fstream>
FileReadWrite::FileReadWrite()
{
}

FileReadWrite::FileReadWrite(const std::string inputFile, const std::string outputFile)
	:mReadFileName(inputFile),
	mOutFileName(outputFile)
{
}

void FileReadWrite::ReadFile()
{
	std::ifstream In(mReadFileName, std::ios::binary);

	if (In.is_open())
	{
		In.seekg(0, std::ios::end);
		mBuffer.resize(In.tellg());
		In.seekg(0, std::ios::beg);

		In.read(&*mBuffer.begin(), mBuffer.size());
	}

	INST_NUM = mBuffer.size() / 4;
	mResultBuffer = new int[INST_NUM];
}

std::string FileReadWrite::GetBuffer() const
{
	return mBuffer;
}

int FileReadWrite::GetInstructinNum() const
{
	return INST_NUM;
}

void FileReadWrite::WriteFile() const
{
	std::ofstream Out(mOutFileName+".txt");
	for (int i = 0; i < mResultBufferIdx; i++)
	{
		Out << (mResultBuffer + i);
		Out << '\t';
		Out << mResultBuffer[i];
		Out << std::endl;
	}
	Out.close();
	return;
}

