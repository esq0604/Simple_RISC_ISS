#pragma once
class Instruction
{
private:
    //�������� ������ ra,rb �����ҵ� 
public:
    Instruction();
    Instruction(int*& const ra, const int*& const rb, const int*& const imm); //TODO : �����ڿ� ��Ʈ���� �迭 ������
    ~Instruction();

    //���� ���� �Լ��� ����ؾ��ҵ�. �Լ����� ����� RegisterA�� �־��ٰ�.
};