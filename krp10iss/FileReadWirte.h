#pragma once
class FileReadWrite
{
public:
	FileReadWrite();
	~FileReadWrite();
	
	void ReadBinFile(const std::string& inputFile);

private:
	const int INST_NUM = 10;
	const int INST_BYTE_SIZE = 4;
	const int INST_BIT_SIZE = 32;
	unsigned char buffer[10 * 4];

};