#pragma once
#include<string>
class Instruction
{
private:
    //레지스터 변수들 ra,rb 들어가야할듯
    unsigned char mbitData[32];
public:
    Instruction();
    Instruction(std::string bitData);
    ~Instruction();

    //연산 관련 함수들 사용해야할듯. 함수들의 결과는 RegisterA에 넣어줄것.
};