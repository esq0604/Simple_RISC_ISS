#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<cstdlib>
#include<bitset>
#include<array>
#include<vector>
#include<stdlib.h>
#include<bit>
#include"instruction.h"

using namespace std;

struct InstructionSet {
    unsigned imm : 17;
    unsigned rb : 5;
    unsigned ra : 5;
    unsigned opcode : 5;
};

string decToHexa(int n)
{
    string ans = "";

    while (n != 0)
    {
        int rem = 0;

        char ch;

        rem = n % 16;

        if (rem < 10)
            ch = rem + 48;
        else
            ch = rem + 55;

        ans += ch;
        n = n / 16;
    }
        int i = 0, j = ans.size() - 1;
        while (i <= j)
        {
            swap(ans[i], ans[j]);
            i++;
            j--;
        }
        return ans;
    
}

int main()
{
    //main에서 file을 받아온뒤 클래스에서 처리하는게 맞는거같음.
    ifstream in("test.txt", std::ios::binary);
    InstructionSet iss;
    string hex_data="";

    unsigned char byte[4];

    int slicing_byte[100];
    int x;
    int dec_data[4];

    if (in.is_open())
    {
        in.seekg(0, std::ios::end);            //위치 지정자를 파일 끝으로        
        int size = in.tellg();                         //위치를 읽음(파일 크기)
        in.seekg(0, std::ios::beg);

        //unsigned char* buffer = (unsigned char*)malloc(size);

        in.seekg(0, std::ios::beg);
        in.read((char*)&byte, size);  //1byte씩 할당. 
     
        //TODO : 4byte -> 1byte씩 슬라이싱, 1byte -> bit단위로 변환 5,5,5,17                      
            //16진수로 바꾼 데이터 파일을 bit형으로 바꾼다. 00000001 000000100 00000001 000000001
            //비트로 바꾼 데이터를 슬라이싱한다 5, 5, 5, 17        
     
        for (int i = 0; i < 4; i++)
        {
            dec_data[i] = (int)byte[i];
        }

        for (int i = 0; i < 4; i++)
        {
            hex_data += decToHexa(dec_data[i]);
        }
        cout << hex_data << endl;

        for (int i = 0; i < 4; i++)
        {
            cout<<hex << int(byte[i]) << ' ';
        }

    }
    else
        cout << "파일을 찾을 수 없습니다!" << endl;


    return 0;

}
