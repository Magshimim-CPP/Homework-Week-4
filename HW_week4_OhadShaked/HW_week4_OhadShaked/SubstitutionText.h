#pragma once
#ifndef SUBSTITUTIONTEXT_H
#define SUBSTITUTIONTEXT_H

//Using iostream, string, fstream, and PlainText header file.
#include "PlainText.h"
#include <iostream>
#include <string>
#include <fstream>

//Using specific functions from the std namespace.
using std::cout;
using std::ifstream;
using std::string;

//Substitution Text class (inherits the Plain Text class).
class SubstitutionText : public PlainText
{

//Setting private class variables.
private:
	string _dictionaryFileName; //stores the name of the dictionary file to open.

//Setting public functions for the SubstitutionText class.
public:
	SubstitutionText(string text, string dictionaryFileName); //Constructor function for a SubstitutionText object.
	~SubstitutionText(); //Destructor function for a SubstitutionText object.
	static string encrypt(string& text, string dictionaryFileName); //Static function to encrypt a given text, in Substitution cipher with the given cipher alphabet file.
	static string decrypt(string& text, string dictionaryFileName); //Static function to decrypt a given text, in Substitution cipher with the given cipher alphabet file.
	string encrypt(); //Function to encrypt the _text field of a SubstitutionText object, in Substitution cipher with the given cipher alphabet file.
	string decrypt(); //Function to decrypt the _text field of a SubstitutionText object, in Substitution cipher with the given cipher alphabet file.
	friend ostream& operator<<(ostream& output, const SubstitutionText& text); //OverLoading for the "<<" operator to output stream: the type of text object, and the text field.
};


#endif