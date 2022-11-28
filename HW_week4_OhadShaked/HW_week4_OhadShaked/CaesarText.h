#pragma once
#ifndef CAESARTEXT_H
#define CAESARTEXT_H

//Using iostream, and ShiftText header file.
#include <iostream>
#include "ShiftText.h"

//Using string from the std namespace.
using std::string;

//setting caesar cipher const key to 3 (as given in part 2).
#define KEY 3

//Caesar Text class (inherits the Shift Text class).
class CaesarText : public ShiftText
{
//Setting public functions for the CaesarText class.
public:
	CaesarText(string text); //Constructor function for a CaesarText object.
	~CaesarText(); //Destructor function for a CaesarText object.
	static string encrypt(string& text); //Static function to encrypt a given text in Caesar cipher with the const key 3.
	static string decrypt(string& text); //Static function to decrypt a given text in Caesar cipher with the const key 3.
	string encrypt(); //Function to encrypt the _text field of a CaesarText object, in Caesar cipher with the const key 3.
	string decrypt(); //Function to decrypt the _text field of a CaesarText object, in Caesar cipher with the const key 3.
	friend ostream& operator<<(ostream& output, const CaesarText& text); //OverLoading for the "<<" operator to output stream: the type of text object, and the text field.
};


#endif
