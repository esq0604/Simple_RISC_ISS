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

struct InstructionSet {
    unsigned imm : 17;
    unsigned rb : 5;
    unsigned ra : 5;
    unsigned opcode : 5;
};

void intSlicing(int a)
{
    vector<int> vec(8);
    int i = 0;
    while (a != 0)
    {
        vec.at(i) = a % 100;
        a /= 100;
        i++;
    }

}

int main()
{
    //main에서 file을 받아온뒤 클래스에서 처리하는게 맞는거같음.
    ifstream in("test.txt", std::ios::binary);
    string strHexData = "";

    DataPreProcessing dataPreProcessing;
    InstructionSet instructionSet;

    unsigned char byte[4];

    if (in.is_open())
    {
        in.seekg(0, std::ios::end);            //위치 지정자를 파일 끝으로        
        int size = in.tellg();                         //위치를 읽음(파일 크기)
        in.seekg(0, std::ios::beg);

        //unsigned char* buffer = (unsigned char*)malloc(size);

        in.seekg(0, std::ios::beg);
        in.read((char*)&byte, size);  //1byte씩 할당.       
    }
    else
        std::cout << "파일을 찾을 수 없습니다!" << endl;

    

    //TODO : 4byte -> 1byte씩 슬라이싱, 1byte -> bit단위로 변환 5,5,5,17                      
        //16진수로 바꾼 데이터 파일을 bit형으로 바꾼다. 00000001 000000100 00000001 000000001
        //16진수 ->10진수 ->bit or 16진수 -> bit 
        //비트로 바꾼 데이터를 슬라이싱한다 5, 5, 5, 17     
    
    for (auto& i : byte)
    {
        std::cout << int(i) << endl;
    }

    return 0;

}
