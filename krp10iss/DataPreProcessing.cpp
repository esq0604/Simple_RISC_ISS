#include<sstream>
#include<bitset>
#include<string>
#include<iostream>
#include"DataPreProcessing.h"

DataPreProcessing::DataPreProcessing()
{

}

DataPreProcessing::~DataPreProcessing()
{
}

//참조배열받기
std::string DataPreProcessing::DecToHex(int(&decNum)[4])
{
    std::string ans = "";
    for (int idx = 0; idx < 4; idx++)
    {
        while (*(decNum+idx) != 0)
        {
            int i = 0;
            int rem = 0;

            char ch;

            rem = *(decNum + idx) % 16;

            if (rem < 10)
                ch = rem + 48;
            else
                ch = rem + 55;

            ans += ch;
            *(decNum + idx) = *(decNum + idx) / 16;
        }
        int i = 0, j = ans.size() - 1;
        while (i <= j)
        {
            std::swap(ans[i], ans[j]);
            i++;
            j--;
        }
    }
    return ans;
}

//..
std::string DataPreProcessing::HexToBin(const std::string& str)
{
    //std::stringstream ss;
    //ss << std::hex << str;

    //unsigned int n;
    //while (ss >> n)
    //    for (int i = 8 - 1; i >= 0; i--)
    //        //cout << ((n >> i) & i) ? "1" : "0";
    
    return str;
}

//진수변환
std::string DataPreProcessing::DecToBin(int(&decNum)[4])
{
    std::string binary;
    for (int i = 0; i < 4; i++)
    {
        binary += std::bitset<8>(*(decNum + i)).to_string();
    }

    mbitData = binary;

    return binary;
}

void DataPreProcessing::BitSlicing(std::string& bitData)
{
  
}
