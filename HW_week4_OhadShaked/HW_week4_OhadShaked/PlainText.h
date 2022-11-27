#pragma once
#ifndef PLAINTEXT_H
#define PLAINTEXT_H

#include <iostream>
#include <string>

using std::string;
using std::ostream;

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
	friend ostream& operator<<(ostream& output, const PlainText& text);
};
#endif