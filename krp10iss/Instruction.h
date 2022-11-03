#pragma once
class Instruction
{
private:
    //레지스터 변수들 ra,rb 들어가야할듯 
public:
    Instruction();
    Instruction(int*& const ra, const int*& const rb, const int*& const imm); //TODO : 생성자에 비트단위 배열 들어가야함
    ~Instruction();

    //연산 관련 함수들 사용해야할듯. 함수들의 결과는 RegisterA에 넣어줄것.
};