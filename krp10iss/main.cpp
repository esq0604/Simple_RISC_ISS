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
    //main에서 file을 받아온뒤 클래스에서 처리하는게 맞는거같음.
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
        in.seekg(0, std::ios::end);            //위치 지정자를 파일 끝으로        
        int size = in.tellg();                         //위치를 읽음(파일 크기)
        in.seekg(0, std::ios::beg);

        //unsigned char* buffer = (unsigned char*)malloc(size);

        in.seekg(0, std::ios::beg);
        in.read((char*)&byte, size);  //1byte씩 할당. 
     
        //TODO : 4byte -> 1byte씩 슬라이싱, 1byte -> bit단위로 변환 
        cout << byte[0] << ' '<< byte[1] << ' '<<byte[2] << ' '<<byte[3] << ' '<<endl;

        for (int i = 0; i < 4; i++)
        {
            cout << int(byte[i]) << ' ';
        }

    }
    else
        cout << "파일을 찾을 수 없습니다!" << endl;


    return 0;

}
