#include<bitset>
#include<string>
#include<iostream>
#include"DataPreProcessing.h"

DataPreProcessing::DataPreProcessing() : DecNum(0)
{

}

DataPreProcessing::~DataPreProcessing()
{
}

//바이너리 파일 -> 리틀엔디안으로
std::string DataPreProcessing::ChangeDecToBinInLittleEndian(const int(&decNum)[4])
{
    std::string temp[4];
    std::string binary;
    std::string byteData;
    for (int i = 3; i >= 0; i--)
    {
        temp[i] = std::bitset<8>(*(decNum + i)).to_string();
    }
    
    for (int i = 3; i >= 0; i--)
    {
        binary += temp[i];
    }
    BitData = binary;
    return binary;
}

std::string DataPreProcessing::ChangeDecToBinForInteger(const int& decNum)
{
    std::string binary = std::bitset<8>(decNum).to_string();
    return binary;
}

uint32_t DataPreProcessing::ChangeBinToByte()
{
    return uint32_t();
}

int DataPreProcessing::ChangeBinToDec(std::string binaryNum) 
{
     return strtol(binaryNum.c_str(), nullptr,2);
}