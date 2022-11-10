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
    //main���� file�� �޾ƿµ� Ŭ�������� ó���ϴ°� �´°Ű���.
    ifstream in("test.txt", std::ios::binary);
    string strHexData = "";

    DataPreProcessing dataPreProcessing;
    InstructionSet instructionSet;

    unsigned char byte[4];

    if (in.is_open())
    {
        in.seekg(0, std::ios::end);            //��ġ �����ڸ� ���� ������        
        int size = in.tellg();                         //��ġ�� ����(���� ũ��)
        in.seekg(0, std::ios::beg);

        //unsigned char* buffer = (unsigned char*)malloc(size);

        in.seekg(0, std::ios::beg);
        in.read((char*)&byte, size);  //1byte�� �Ҵ�.       
    }
    else
        std::cout << "������ ã�� �� �����ϴ�!" << endl;

    

    //TODO : 4byte -> 1byte�� �����̽�, 1byte -> bit������ ��ȯ 5,5,5,17                      
        //16������ �ٲ� ������ ������ bit������ �ٲ۴�. 00000001 000000100 00000001 000000001
        //16���� ->10���� ->bit or 16���� -> bit 
        //��Ʈ�� �ٲ� �����͸� �����̽��Ѵ� 5, 5, 5, 17     
    
    for (auto& i : byte)
    {
        std::cout << int(i) << endl;
    }

    return 0;

}
