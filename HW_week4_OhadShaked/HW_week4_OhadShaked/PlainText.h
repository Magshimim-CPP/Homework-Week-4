#pragma once
#ifndef PLAINTEXT_H
#define PLAINTEXT_H

#include <iostream>
#include <string>

using std::string;

class PlainText
{
protected:
	string _text;
	bool _isEncrypted;

public:
	PlainText(string text);
	~PlainText();
	bool isEncrypted() const;
	string getText() const;

};
#endif