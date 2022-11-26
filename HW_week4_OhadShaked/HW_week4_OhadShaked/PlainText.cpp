#include "PlainText.h"

PlainText::PlainText(string text)
{
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