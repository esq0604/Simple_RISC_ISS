#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
#include<vector>
#include<stdlib.h>
#include"instruction.h"
#include"DataPreProcessing.h"

using namespace std;

int main()
{
    ifstream in("test.txt", std::ios::binary);
    string strHexData = "";
    DataPreProcessing dataPreProcessing;
    const int byteSize = 4;
    int decNum[byteSize];
    unsigned char byte[byteSize];
    string strbitData;


    //file open
    if (in.is_open())
    {
        in.seekg(0, std::ios::end);                   
        int size = in.tellg();                         
        in.seekg(0, std::ios::beg);


        in.seekg(0, std::ios::beg);
        in.read((char*)&byte, size);       
    }
    else
        std::cout << "파일을 찾을 수 없습니다!" << endl;

    
    //char to int
    for (int i=0; i<4; i++)
    {
        cout<<"dec num : " << int(byte[i]) << endl;
        decNum[i] = int(byte[i]);
    }

    //dec to bit
    strbitData=dataPreProcessing.DecToBin(decNum);

    Instruction(strbitData);


    return 0;

}
