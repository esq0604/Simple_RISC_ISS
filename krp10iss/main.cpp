#pragma once
#include<iostream>
#include<fstream>
#include<string>

#include"DataPreProcessing.h"
#include"instruction.h"
#include"Draw.h"

using namespace std;

const int INST_NUM = 10;
const int INST_BYTE_SIZE = 4;
const int INST_BIT_SIZE = 32;
int decNum[INST_NUM * INST_BYTE_SIZE];
unsigned char buffer[INST_BYTE_SIZE * INST_NUM];

class DataPreProcessing dataPreProcessing; 
class Draw Draw;
string bitData;
string instSet[10];

void ProcessingData();
void PrintInstSet();
int main()
{
    ifstream In("input_file", std::ios::binary);

    //file open
    if (In.is_open())
    {
        In.seekg(0, std::ios::end);
        int size = In.tellg();
        In.seekg(0, std::ios::beg);

        In.read((char*)buffer, size);
        In.close();

        
    }


    //DataProcessing
    ProcessingData();
    //DrawMenu
    Draw.DrawMainMenu();
    //Operation 
    PrintInstSet();
    Instruction Instruction(instSet);
    Instruction.SetCommand(getchar());
    Instruction.OperInstSet();
    return 0;

}

void ProcessingData()
{
    //char to int
    for (int i = 0; i < INST_NUM * INST_BYTE_SIZE; ++i)
    {
        decNum[i] = buffer[i];
    }

    //dec to bit && data preprocessing
    bitData = dataPreProcessing.ChangeDecToBinForInst(decNum);

    for (int i = 0; i < INST_NUM; ++i)
    {
        for (int j = 0; j < INST_BIT_SIZE; ++j)
        {
            instSet[i] += bitData[i * INST_BIT_SIZE + j];
        }
    }

}

void PrintInstSet()
{
    for (auto i : instSet)
    {
        cout << i << endl;
    }
}