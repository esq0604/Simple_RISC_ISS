#pragma once
#include<iostream>
#include<fstream>
#include<string>

#include"DataPreProcessing.h"
#include"Instruction.h"
#include"Draw.h"

using namespace std;

const int INST_NUM = 10;
const int INST_BYTE_SIZE = 4;
const int INST_BIT_SIZE = 32;
int decNum[INST_NUM][INST_BYTE_SIZE];
unsigned char buffer[INST_BYTE_SIZE * INST_NUM];
string instSet[INST_NUM];
DataPreProcessing* dataPreProcessing = new DataPreProcessing();



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

    Instruction* instruction = new Instruction(instSet, dataPreProcessing);
    Draw* draw = new Draw(instruction);
    //DrawMenu
    draw->DrawMainMenu();

    while (true)
    {
        if (instruction->GetPC() >= INST_NUM)
            break;

        char flag;
        cin >> flag;

        instruction->SetCommand(flag);
        if (instruction->GetCommand()=='r')
        {
            for (int i = instruction->GetPC(); i < INST_NUM; i++)
            {
                instruction->OperInstSet();
            }
            draw->DrawPC();
            draw->DrawRegState();
            break;
        }
        else if (instruction->GetCommand() == 's')
        {

            instruction->OperInstSet();
            //draw->DrawInstByte(); TODO 이진수 ->10진수
            draw->DrawPC();
            draw->DrawRegState();
            instruction->GetDataAddress();
        }
     
    }

   
    return 0;

}

void ProcessingData()
{
    //char to int
    for (int i = 0; i < INST_NUM; ++i)
    {
        for (int j = 0; j < INST_BYTE_SIZE; j++)
        {
            decNum[i][j] = buffer[i* INST_BYTE_SIZE + j];
        }
    }

    //dec to bit && data preprocessing
    for (int i = 0; i < INST_NUM; i++)
    {
        instSet[i] = dataPreProcessing->ChangeDecToBinInLittleEndian(decNum[i]);
    }
}

