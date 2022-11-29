#pragma once
#ifndef FILEHELPER_H
#define FILEHELPER_H

//Using iostream, string, fstream, and PlainText header file.
#include <iostream>
#include <string>
#include <fstream>
#include "PlainText.h"

//Using specific functions from the std namespace.
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;

//Defining constant values for ZERO (0)
#define ZERO 0

//Defining text errors in case a file was not found or could not be opend.
#define FILE_NOT_FOUND "ERROR: File was not found or was unable to open!"
#define ONE_OR_MORE_FILES_NOT_FOUND "ERROR: One or more file were not found or was unable to open!"

//File Helper Class.
class FileHelper
{
public:
	static string readFileToString(string fileName); //Static function recives a file's name, opens it, reads the file's content to a string, and returns the string.
	static void writeWordsToFile(string inputFileName, string outputFileName); //Static function writes the content of one file to another file.
	static void saveTextInFile(string text, string outputFileName); //Static function saves a string text inside the output file.
};


#endif