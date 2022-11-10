#pragma 
#include<string>

class DataPreProcessing
{
public:
	DataPreProcessing();
	~DataPreProcessing();

	std::string DecToHex(const int*& decNum);
	std::string HexToBin(const std::string& str);
	
private:
	std::string mHexData;
	std::string mBitData;
	
};