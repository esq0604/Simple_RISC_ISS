#include<bitset>
#include<string>
#include<iostream>
#include"DataPreProcessing.h"
#include"FileReadWrite.h"

DataPreProcessing::DataPreProcessing() 
{
	mInst.resize(10);
}

DataPreProcessing::~DataPreProcessing()
{
}



void DataPreProcessing::SetFileReadWrite(FileReadWrite*& fileReadWrite)
{
	mFileReadWrite = fileReadWrite;
}

std::string DataPreProcessing::GetInstData() const
{
	return mInst;
}

std::vector<std::string> DataPreProcessing::ConvertInputFileToProcessableData()
{
	const int INST_SET_NUM = mFileReadWrite->GetInstructinNum();
	mInst = (mFileReadWrite->GetBuffer());
	std::vector<std::string> inst_set;
	inst_set.resize(INST_SET_NUM);
	for (int i = 0; i < INST_SET_NUM; i++)
	{
		for (int j = INST_SET_BYTE_SIZE - 1; j >= 0; j--)
		{
			inst_set[i] += (std::bitset<8>(int(mInst[i * INST_SET_BYTE_SIZE + j])).to_string());
		}
	}
	return inst_set;
}





int DataPreProcessing::ChangeBinToDec(std::string binaryNum)
{
	return strtol(binaryNum.c_str(), nullptr, 2);
}