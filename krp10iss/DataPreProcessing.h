#pragma 
#include<string>


class DataPreProcessing
{

public:
	DataPreProcessing();
	~DataPreProcessing();

	std::string DecToHex(int(&decNum)[4]);
	std::string HexToBin(const std::string& str);
	std::string DecToBin(int(&decNum)[4]);
	

private:
	unsigned char bit[32];

	std::string mhexData;
	std::string mbitData;
	

	void BitSlicing(std::string& bitData);
};