#pragma once
#include<iostream>
#include<fstream>
#include<string>

#include "FileReadWrite.h"
#include"DataPreProcessing.h"
#include"Instruction.h"
#include"Draw.h"

using namespace std;

int main()
{
    FileReadWrite* fileReadWirte = new FileReadWrite(string("input_file"), string("output_file"));
    fileReadWirte->ReadFile();

    DataPreProcessing* dataPreProcessing = new DataPreProcessing();
    dataPreProcessing->SetFileReadWrite(fileReadWirte);
    
    Instruction* instruction = new Instruction(dataPreProcessing->ConvertInputFileToProcessableData()); //Fetch
    instruction->SetFileReadWrite(fileReadWirte);
    instruction->SetDataPreProcessing(dataPreProcessing);
   
    Draw* draw = new Draw();
    draw->SetInstruction(instruction);
    draw->SetDatePreProcessing(dataPreProcessing);
    draw->DrawMainMenu();


    while (true)
    {
        if (instruction->GetPC() >= fileReadWirte->GetInstructinNum())
            break;

        char flag;
        cin >> flag;

        instruction->SetCommand(flag);
        if (instruction->GetCommand()=='r')
        {
            for (int i = instruction->GetPC(); i < fileReadWirte->GetInstructinNum(); i++)
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
            draw->DrawPC();
            draw->DrawInstByte();
            draw->DrawRegState();
            instruction->GetDataAddress();
        }
     
    }

    fileReadWirte->WriteFile();
    return 0;

}


