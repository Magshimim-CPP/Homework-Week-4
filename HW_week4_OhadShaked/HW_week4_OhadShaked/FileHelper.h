#pragma once
#pragma once
#ifndef FILEHELPER_H
#define FILEHELPER_H

#include <iostream>
#include <string>
#include <fstream>
#include "PlainText.h"

using std::string;
using std::ifstream;
using std::ofstream;

#define ZERO 0

class FileHelper
{
public:
	static string readFileToString(string fileName);
	static void writeWordsToFile(string inputFileName, string outputFileName);
	static void saveTextInFile(string text, string outputFileName);
};


#endif