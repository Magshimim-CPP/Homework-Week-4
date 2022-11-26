#pragma once
#ifndef CAESARTEXT_H
#define CAESARTEXT_H

#include <iostream>
#include "ShiftText.h"
using std::string;

class CaesarText : public ShiftText
{
public:
	CaesarText(string text);
	~CaesarText();
	static string encrypt(string& text);
	static string decrypt(string& text);
	string encrypt();
	string decrypt();
};


#endif
