#pragma once
#ifndef PLAINTEXT_H
#define PLAINTEXT_H

#include <iostream>
#include <string>

using std::string;

#define ZERO 0

class PlainText
{
protected:
	string _text;
	bool _isEncrypted;

public:
	static int numOfTexts;
	PlainText(string text);
	~PlainText();
	bool isEncrypted() const;
	string getText() const;

};
#endif