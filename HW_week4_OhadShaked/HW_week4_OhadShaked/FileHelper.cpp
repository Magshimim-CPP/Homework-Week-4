#include "FileHelper.h"

string FileHelper::readFileToString(string fileName)
{
	string result;
	ifstream file;
	char ch;

	file.open(fileName);

	while (file.good())
	{
		file.get(ch);

		if (file.good())
		{
			result += ch;
		}
		
	}

	file.close();

	return result;
}

void FileHelper::writeWordsToFile(string inputFileName, string outputFileName)
{
	string result;
	ifstream inFile;
	ofstream outFile;

	outFile.open(outputFileName);
	inFile.open(inputFileName);

	while (inFile.good())
	{
		inFile >> result;
		outFile << result;

		if (inFile.good())
		{
			outFile << '\n';
		}
	}

	inFile.close();
	outFile.close();
}

void FileHelper::saveTextInFile(string text, string outputFileName)
{
	ofstream outFile;

	outFile.open(outputFileName);

	for (int i = ZERO; i < text.length(); i++)
	{
		outFile << text[i];
	}

	outFile.close();
}