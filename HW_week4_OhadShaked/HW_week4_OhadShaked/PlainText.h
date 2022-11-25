#pragma once
#ifndef PLAINTEXT_H
#define PLAINTEXT_H

#include <iostream>
using std::string;

class PlainText
{
protected:
	string _text;
	bool _isEncrypted;

public:
	PlainText(string text);
	~PlainText();
	bool isEncrypted();
	string getText();
};


#endif