#include "PlainText.h"

int PlainText::numOfTexts = 0;

PlainText::PlainText(string text)
{
	PlainText::numOfTexts++;
	_text = text;
	_isEncrypted = false;
}

PlainText::~PlainText()
{
	_text = "";
	_isEncrypted = false;
}

bool PlainText::isEncrypted() const
{
	return _isEncrypted;
}

string PlainText::getText() const
{
	return _text;
}