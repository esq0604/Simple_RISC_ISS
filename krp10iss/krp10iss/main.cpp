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

	const string filename = "file.txt";

	// Reading
	if (false)
	{
		ifstream ifs(filename);

		if (!ifs) { std::cerr << "Opening file error\n"; exit(EXIT_FAILURE); }

		const unsigned num_data = 0;
		ifs.read((char*)&num_data, sizeof(num_data));

		for (int i = 0; i < num_data; ++i)
		{
			int num;
			ifs.read((char*)&num, sizeof(num));
			std::cout << num << endl;
		}
	}
	const int len_data = 5; 
	Instruction inst_arr[len_data];
	
}