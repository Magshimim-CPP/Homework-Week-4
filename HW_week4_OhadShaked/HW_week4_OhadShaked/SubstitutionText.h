#pragma once
#ifndef SUBSTITUTIONTEXT_H
#define SUBSTITUTIONTEXT_H

#include <iostream>
using std::string;

class SubstitutionText
{
protected:
	string dictionaryFileName;

public:
	SubstitutionText(string text, string dictionaryFileName);
	~SubstitutionText();
	string encrypt(string text, string dictionaryFileName);
	string decrypt(string text, string dictionaryFileName);
	string encrypt();
	string decrypt();
};


#endif