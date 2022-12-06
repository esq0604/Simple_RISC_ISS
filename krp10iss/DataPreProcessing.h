#pragma 

class DataPreProcessing
{
private:
	const int INST_LEN = 10;
	
	std::string mByteData[10];

public:
	DataPreProcessing();
	~DataPreProcessing();

	std::string ChangeDecToBinInLittleEndian(const int(&decNum)[4]);
	std::string ChangeDecToBinForInteger(const int& decNum);
	uint32_t ChangeBinToByte();
	int ChangeBinToDec(std::string binaryNum);

public:
	int DecNum;

	std::string BitData;

};