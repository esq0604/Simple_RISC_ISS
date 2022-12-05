#pragma once
#include<string>

using namespace std;

class DataPreProcessing;

class Instruction
{
private:
    DataPreProcessing* mDataPreProcessing;
    string mImm[10];
    string mRa[10];
    string mRb[10];
    string mOper[10];
    string mInstSet[10];
    int mReg[32];
    char mCommand;
    int mPC;
    

     
public:
    Instruction(string instSet[]);
    ~Instruction();
    void OperInstSet();
    void SetCommand(const char& command);

    //연산 관련 함수들 사용해야할듯. 함수들의 결과는 RegisterA에 넣어줄것.
};