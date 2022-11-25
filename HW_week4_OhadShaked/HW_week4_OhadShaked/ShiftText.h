#pragma once
#ifndef SHIFTTEXT_H
#define SHIFTTEXT_H

#include <iostream>
using std::string;

class ShiftText
{
protected:
	int _key;

public:
	ShiftText(string text, int key);
	~ShiftText();
	string encrypt(string text, int key);
	string decrypt(string text, int key);
	string encrypt();
	string decrypt();
};


#endif