#pragma once
#include<string>
class Instruction
{
private:
    //�������� ������ ra,rb �����ҵ�
    unsigned char mbitData[32];
public:
    Instruction();
    Instruction(std::string bitData);
    ~Instruction();

    //���� ���� �Լ��� ����ؾ��ҵ�. �Լ����� ����� RegisterA�� �־��ٰ�.
};