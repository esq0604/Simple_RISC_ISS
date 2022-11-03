#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<cstdlib>
#include<bitset>
#include"instruction.h"

using namespace std;

int main()
{
    //main에서 file을 받아온뒤 클래스에서 처리하는게 맞는거같음.
    ifstream in("test2.txt", std::ios::binary);
    string s;

    int x[2];
    if (in.is_open())
    {
        in.seekg(0, std::ios::end);            //위치 지정자를 파일 끝으로        
        int size = in.tellg();                  //위치를 읽음(파일 크기)
        in.seekg(0, std::ios::beg);

        //unsigned char* buffer = (unsigned char*)malloc(size);

        in.seekg(0, std::ios::beg);
        in.read((char*)x, size);
     
        cout << hex << x[0] << endl << x[1] << endl;
    }
    else
        cout << "파일을 찾을 수 없습니다!" << endl;


    return 0;

}
