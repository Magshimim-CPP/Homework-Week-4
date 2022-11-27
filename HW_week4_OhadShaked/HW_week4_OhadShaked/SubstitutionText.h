#pragma once
#ifndef SUBSTITUTIONTEXT_H
#define SUBSTITUTIONTEXT_H

#include "PlainText.h"
#include <iostream>
#include <string>
#include <fstream>

using std::cout;
using std::ifstream;
using std::string;

#define ALPHABET "abcdefghijklmnopqrstuvwxyz"

class SubstitutionText : public PlainText
{
private:
	string _dictionaryFileName;

public:
	SubstitutionText(string text, string dictionaryFileName);
	~SubstitutionText();
	static string encrypt(string& text, string dictionaryFileName);
	static string decrypt(string& text, string dictionaryFileName);
	string encrypt();
	string decrypt();
	friend ostream& operator<<(ostream& output, const SubstitutionText& text);
};


#endif