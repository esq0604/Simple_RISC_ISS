#pragma 

class DataPreProcessing
{
private:
	const int INST_LEN = 10;
	const int BYTE_SIZE = 4;
	void sliceBit(std::string& bitData);
	
public:
	DataPreProcessing();
	~DataPreProcessing();

	std::string ChangeDecToBinForInst(const int(&decNum)[40]);
	std::string ChangeDecToBinForInteger(const int& decNum);
	int ChangeBinToDec(std::string binaryNum);

public:
	int DecNum;

	std::string BitData;

};