#include "PlainText.h"

//Setting static (numOfTexts) variable to 0 at the start of the file.
int PlainText::numOfTexts = ZERO;

/*
Constructor function for a PlainText object.
Input: const string text
Output: none
*/
PlainText::PlainText(const string text)
{
	PlainText::numOfTexts++; //counting number of created texts.
	_text = text;
	_isEncrypted = false;
}

/*
Destructor function for a PlainText object.
Input: none
Output: none
*/
PlainText::~PlainText()
{
	_text = "";
	_isEncrypted = false;
}

/*
Const 'get' function that returns the device's _isEncrypted field (bool true/false).
Input: none
Output: the device's _isEncrypted field (bool true/false).
*/
bool PlainText::isEncrypted() const
{
	return _isEncrypted;
}

/*
Const 'get' function that returns the device's _text field (string).
Input: none
Output: the device's _text field (string).
*/
string PlainText::getText() const
{
	return _text;
}

/*
OverLoading for the "<<" operator to output stream: the type of text object, and the _text field.
Input: ostream& output (where to output to), const PlainText& text (the object with the text to output)
Output: the object's type and text field (outputed using ostream& output).
*/
ostream& operator<<(ostream& output, const PlainText& text)
{
	output << "Plain\n\n" << text._text;
	return output;
}