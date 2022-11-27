#pragma once
#ifndef SHIFTTEXT_H
#define SHIFTTEXT_H

#include <iostream>
#include "PlainText.h"

using std::string;

#define ZERO 0

class ShiftText : public PlainText
{
protected:
	int _key;

public:
	ShiftText(string text, int key);
	~ShiftText();
	static string encrypt(string& text, int key);
	static string decrypt(string& text, int key);
	string encrypt();
	string decrypt();
	static char decryptLetter(string text, int place, int key);
	static char encryptLetter(string text, int place, int key);
	friend ostream& operator<<(ostream& output, const ShiftText& text);
};


#endif