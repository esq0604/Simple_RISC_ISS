#pragma once
#include<string>
#include<vector>
using namespace std;

class DataPreProcessing;

class Instruction
{
private:
    enum { INST_NUM = 10 };
    const int REG_SIZE = 32;
    const int INT_BIT = 32;

    DataPreProcessing* mDataPreProcessing;
    std::vector<pair<int*, int>> mAddressAndVal;
    std::vector<int> mReg;

    string mImm[INST_NUM];
    string mRa[INST_NUM];
    string mRb[INST_NUM];
    string mRc[INST_NUM];
    string mOpcode[INST_NUM];
    string mInstSet[INST_NUM];
    string mByte[INST_NUM];
    string mDataMemory[INST_NUM];
    string mI[INST_NUM];
    string mShamt[INST_NUM];
    string mCond[INST_NUM];
    string mImm22[INST_NUM];

    char mCommand;
    int mPC;
    
public:
    Instruction(string instSet[], DataPreProcessing*& dataPreProceccing);
    ~Instruction();
    void OperInstSet();
    void SetCommand(const char& command);
    
    const int GetPC() const;
    const char GetCommand() const;
    const vector<int>& GetRegState() const;
    string GetByte() const;
    void GetDataAddress() const;
    //연산 관련 함수들 사용해야할듯. 함수들의 결과는 RegisterA에 넣어줄것.
};