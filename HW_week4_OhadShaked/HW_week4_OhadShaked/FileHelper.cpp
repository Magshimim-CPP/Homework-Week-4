#include "FileHelper.h"

/*
Static function recives a file's name, opens it, reads the file's content to a string, and returns the string.
Input: string fileName
Output: string result
*/
string FileHelper::readFileToString(string fileName)
{
	string result; //string for the result
	ifstream file; //file stream variable (read)
	char ch; //char for the current letter when reading the file

	file.open(fileName); //opening the file.

	if (file) //if a file with the given name exists 
	{
		while (file) //looping until the end of the file.
		{
			file.get(ch); //reading the current letter

			if (file) //checking if file reached end of file after reading the letter (entering if it didn't reach EOF).
			{
				result += ch; //adding the current char to the result.
			}

		}

		file.close(); //closing the file.
	}

	//else, if a file with the given name dose not exists 
	else
	{
		result = FILE_NOT_FOUND; //setting the result to a error message string.
	}

	return result; //returning the result string.
}

/*
Static function writes the content of one file to another file.
Input: string inputFileName, string outputFileName
Output: none
*/
void FileHelper::writeWordsToFile(string inputFileName, string outputFileName)
{
	string line; //string for storing the current line when reading the file.
	ifstream inFile; //file stream variable (read)
	ofstream outFile; //file stream variable (write)

	//opening the files
	outFile.open(outputFileName);
	inFile.open(inputFileName);

	if (outFile && inFile) //entering condition if both files exist.
	{
		while (inFile.good()) //checking if file's stream is good (if it raised any error or not).
		{
			inFile >> line; //reading the current line
			outFile << line; //entering the line to the output file

			if (inFile.good()) //checking if file's stream is still good after reading the letter (if it raised any error or not).
			{
				outFile << '\n';
			}
		}

		//closing the files
		inFile.close();
		outFile.close(); 
	}
	else //if one or more files dosent exist.
	{
		cout << ONE_OR_MORE_FILES_NOT_FOUND << endl; //printing error message.
	}
}

/*
Static function saves a string text inside the output file
Input: string text, string outputFileName
Output: none
*/
void FileHelper::saveTextInFile(string text, string outputFileName)
{
	ofstream outFile; //file stream variable (write)

	outFile.open(outputFileName); //opening the file.

	if (outFile) //if a file with the given name exists 
	{
		for (int i = ZERO; i < text.length(); i++) //looping for each letter of the text.
		{
			outFile << text[i]; //inserting the current letter to the output file.
		}

		outFile.close(); //closing the file.
	}

	else //if a file with the given name dosent exist
	{
		cout << FILE_NOT_FOUND << endl; //printing error message
	}
}