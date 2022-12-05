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

//진수변환
std::string DataPreProcessing::ChangeDecToBinForInst(const int(&decNum)[40])
{
    std::string binary;
    for (int i = 0; i < 40; i++)
    {
        binary += std::bitset<8>(*(decNum + i)).to_string();
    }

    BitData = binary;
    return binary;
}

std::string DataPreProcessing::ChangeDecToBinForInteger(const int& decNum)
{
    std::string binary = std::bitset<8>(decNum).to_string();
    return binary;
}

int DataPreProcessing::ChangeBinToDec(std::string binaryNum)
{
     return strtol(binaryNum.c_str(), nullptr,2);
}