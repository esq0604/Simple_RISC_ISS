#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<cstdlib>
#include<bitset>
#include"instruction.h"
#include<bitset>
#include<array>
#include<stdlib.h>
#include<bit>
#include<vector>
using namespace std;

int main()
{
    //main���� file�� �޾ƿµ� Ŭ�������� ó���ϴ°� �´°Ű���.
    ifstream in("test.txt", std::ios::binary);
    string s;

    int slicing_byte[100];
    int x;
    unsigned char byte[4];

    struct iss {
        unsigned imm : 17;
        unsigned rb : 5;
        unsigned ra : 5;
        unsigned opcode : 5;
    };

    
    if (in.is_open())
    {
        in.seekg(0, std::ios::end);            //��ġ �����ڸ� ���� ������        
        int size = in.tellg();                         //��ġ�� ����(���� ũ��)
        in.seekg(0, std::ios::beg);

        //unsigned char* buffer = (unsigned char*)malloc(size);

        in.seekg(0, std::ios::beg);
        in.read((char*)&byte, size);  //1byte�� �Ҵ�. 
     
        //TODO : 4byte -> 1byte�� �����̽�, 1byte -> bit������ ��ȯ 
        cout << byte[0] << ' '<< byte[1] << ' '<<byte[2] << ' '<<byte[3] << ' '<<endl;

        for (int i = 0; i < 4; i++)
        {
            cout << int(byte[i]) << ' ';
        }

    }
    else
        cout << "������ ã�� �� �����ϴ�!" << endl;


    return 0;

}
