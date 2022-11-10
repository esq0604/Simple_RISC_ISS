#include<sstream>
#include<bitset>
#include<string>
#include"DataPreProcessing.h"

DataPreProcessing::DataPreProcessing()
{

}

DataPreProcessing::~DataPreProcessing()
{
}

//참조배열받기
std::string DataPreProcessing::DecToHex(const int*& decNum)
{
    std::string ans = "";

    while (decNum != 0)
    {
        int i = 0;
        int rem = 0;

        char ch;

        rem = (decNum+i) % 16;

        if (rem < 10)
            ch = rem + 48;
        else
            ch = rem + 55;

        ans += ch;
        decNum = decNum / 16;
    }
    int i = 0, j = ans.size() - 1;
    while (i <= j)
    {
        std::swap(ans[i], ans[j]);
        i++;
        j--;
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
