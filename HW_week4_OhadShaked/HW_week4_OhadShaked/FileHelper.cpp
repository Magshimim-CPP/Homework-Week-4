#include "FileHelper.h"

string FileHelper::readFileToString(string fileName)
{
	string result;
	ifstream file;
	char ch;

	file.open(fileName);

	if (file)
	{
		while (file)
		{
			file.get(ch);

			if (file)
			{
				result += ch;
			}

		}

		file.close();
	}
	else
	{
		result = FILE_NOT_FOUND;
	}

	return result;
}

void FileHelper::writeWordsToFile(string inputFileName, string outputFileName)
{
	string result;
	ifstream inFile;
	ofstream outFile;

	outFile.open(outputFileName);
	inFile.open(inputFileName);

	if (outFile && inFile)
	{
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
	else
	{
		cout << ONE_OR_MORE_FILES_NOT_FOUND << endl;
	}
}

void FileHelper::saveTextInFile(string text, string outputFileName)
{
	ofstream outFile;

	outFile.open(outputFileName);

	if (outFile)
	{
		for (int i = ZERO; i < text.length(); i++)
		{
			outFile << text[i];
		}

		outFile.close();
	}

	else
	{
		cout << FILE_NOT_FOUND << endl;
	}
}