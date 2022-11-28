#pragma once
#ifndef SHIFTTEXT_H
#define SHIFTTEXT_H

//Using iostream, and PlainText header file.
#include <iostream>
#include "PlainText.h"

//Using string from the std namespace.
using std::string;

//Defining constant variable for zero.
#define ZERO 0

//Shift Text class (inherits the Plain Text class).
class ShiftText : public PlainText
{

//Setting protected class variables.
protected:
	int _key; //encryption/decryption key number.

//Setting public functions for the ShiftText class.
public:
	ShiftText(string text, int key); //Constructor function for a ShiftText object.
	~ShiftText(); //Destructor function for a ShiftText object.
	static string encrypt(string& text, int key); //Static function to encrypt a given text, in shift cipher with the given key.
	static string decrypt(string& text, int key); //Static function to decrypt a given text, in shift cipher with the given key.
	string encrypt(); //Function to encrypt the _text field of a ShiftText object, in shift cipher with the key field as encryption key.
	string decrypt(); //Function to decrypt the _text field of a ShiftText object, in shift cipher with the key field as decryption key.
	static char decryptLetter(const string text, const int place, const int key); //Function decrypt's a letter in shift cipher format. (self added, not requested)
	static char encryptLetter(const string text, const int place, const int key); //Function encrypt's a letter in shift cipher format. (self added, not requested)
	friend ostream& operator<<(ostream& output, const ShiftText& text); //OverLoading for the "<<" operator to output stream: the type of text object, and the text field.
};


#endif