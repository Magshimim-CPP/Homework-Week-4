#pragma once
#pragma once
#ifndef FILEHELPER_H
#define FILEHELPER_H

#include <iostream>
#include <string>
#include <fstream>
#include "PlainText.h"

using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;

#define ZERO 0
#define FILE_NOT_FOUND "ERROR: File was not found or was unable to open!"
#define ONE_OR_MORE_FILES_NOT_FOUND "ERROR: One or more file were not found or was unable to open!"

class FileHelper
{
public:
	static string readFileToString(string fileName);
	static void writeWordsToFile(string inputFileName, string outputFileName);
	static void saveTextInFile(string text, string outputFileName);
};


#endif