#pragma 
#include<vector>
class FileReadWrite;

class DataPreProcessing
{
public:
	DataPreProcessing();
	~DataPreProcessing();

	void SetFileReadWrite( FileReadWrite*&  fileReadWrite);
	
	std::string GetInstData() const;
	std::vector<std::string> ConvertInputFileToProcessableData();
	int ChangeBinToDec(std::string binaryNum);

public:

private:
	const int INST_SET_BYTE_SIZE = 4;
	const FileReadWrite* mFileReadWrite;
	std::string mInst;


};