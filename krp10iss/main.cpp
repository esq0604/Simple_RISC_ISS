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
    //main���� file�� �޾ƿµ� Ŭ�������� ó���ϴ°� �´°Ű���.
    ifstream in("test2.txt", std::ios::binary);
    string s;

    int x[2];
    if (in.is_open())
    {
        in.seekg(0, std::ios::end);            //��ġ �����ڸ� ���� ������        
        int size = in.tellg();                  //��ġ�� ����(���� ũ��)
        in.seekg(0, std::ios::beg);

        //unsigned char* buffer = (unsigned char*)malloc(size);

        in.seekg(0, std::ios::beg);
        in.read((char*)x, size);
     
        cout << hex << x[0] << endl << x[1] << endl;
    }
    else
        cout << "������ ã�� �� �����ϴ�!" << endl;


    return 0;

}
