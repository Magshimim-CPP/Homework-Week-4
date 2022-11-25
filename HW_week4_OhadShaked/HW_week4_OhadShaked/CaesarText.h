#pragma once
#ifndef CAESARTEXT_H
#define CAESARTEXT_H

#include <iostream>
using std::string;

class CaesarText
{
public:
	CaesarText(string text);
	~CaesarText();
	string encrypt(string text);
	string decrypt(string text);
	string encrypt();
	string decrypt();
};


#endif
