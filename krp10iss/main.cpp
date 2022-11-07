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
    //main���� file�� �޾ƿµ� Ŭ�������� ó���ϴ°� �´°Ű���.
    ifstream in("test.txt", std::ios::binary);
    InstructionSet iss;
    string hex_data="";

    unsigned char byte[4];

    int slicing_byte[100];
    int x;
    int dec_data[4];

    if (in.is_open())
    {
        in.seekg(0, std::ios::end);            //��ġ �����ڸ� ���� ������        
        int size = in.tellg();                         //��ġ�� ����(���� ũ��)
        in.seekg(0, std::ios::beg);

        //unsigned char* buffer = (unsigned char*)malloc(size);

        in.seekg(0, std::ios::beg);
        in.read((char*)&byte, size);  //1byte�� �Ҵ�. 
     
        //TODO : 4byte -> 1byte�� �����̽�, 1byte -> bit������ ��ȯ 5,5,5,17                      
            //16������ �ٲ� ������ ������ bit������ �ٲ۴�. 00000001 000000100 00000001 000000001
            //��Ʈ�� �ٲ� �����͸� �����̽��Ѵ� 5, 5, 5, 17        
     
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
        cout << "������ ã�� �� �����ϴ�!" << endl;


    return 0;

}
