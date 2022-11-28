#pragma once
#ifndef PLAINTEXT_H
#define PLAINTEXT_H

//Using iostream, and string.
#include <iostream>
#include <string>

//Using specific functions from the std namespace.
using std::string;
using std::ostream;

//Defining constant variable for zero.
#define ZERO 0

//Plain Text class.
class PlainText
{

//Setting protected class variables.
protected:
	string _text; //String field for the text.
	bool _isEncrypted; //Bool field (true/false) that tells us if the text field is encrypted or not.

//Setting public functions for the PlainText class.
public:
	static int numOfTexts; //Static variable to count the number of text objects created.
	PlainText(const string text); //Constructor function for a PlainText object.
	~PlainText(); //Destructor function for a PlainText object.
	bool isEncrypted() const; //Function returns the _isEncrypted field value (bool true/false)
	string getText() const; //Function returns the _text field value (string text)
	friend ostream& operator<<(ostream& output, const PlainText& text); //OverLoading for the "<<" operator to output stream: the type of text object, and the text field.
};
#endif