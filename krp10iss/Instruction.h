#pragma once
#include<string>
#include<vector>
using namespace std;

class DataPreProcessing;
class FileReadWrite;
class Instruction
{
public:
    Instruction(vector<string> instSet);
    ~Instruction();

    void OperInstSet();

    //Setter
    void SetCommand(const char& command);
    void SetDataPreProcessing(DataPreProcessing*&  dataPreProcessing);
    void SetFileReadWrite(FileReadWrite*&  fileReadWrite);

    //Getter
    const int GetPC() const;
    const char GetCommand() const;
    const vector<int>& GetRegState() const;
    void GetDataAddress() const;

private:
    enum { INST_NUM = 10 };
    const int REG_SIZE = 32;
    const int INT_BIT = 32;

    DataPreProcessing* mDataPreProcessing;
    FileReadWrite* mFileReadWrite;
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
    
};