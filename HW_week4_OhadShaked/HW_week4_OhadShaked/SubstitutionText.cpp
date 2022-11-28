#include "SubstitutionText.h"

/*
Constructor function for a SubstitutionText object (also using PlainText constructor).
Input: string text, string dictionaryFileName
Output: none
*/
SubstitutionText::SubstitutionText(string text, string dictionaryFileName) : PlainText(text)
{
	_dictionaryFileName = dictionaryFileName;
	_text = encrypt(text, dictionaryFileName); //Setting the _text field to the encrypted given string (text).
	_isEncrypted = true;
}

/*
Destructor function for a SubstitutionText object.
Input: none
Output: none
*/
SubstitutionText::~SubstitutionText()
{
	//activating PlainText fields destructor.
	PlainText::~PlainText();
	//reseting the dictionary file name
	_dictionaryFileName = "";
}

/*
Static function to encrypt a given text, in Substitution cipher with the given cipher alphabet file.
Input: string& text, string dictionaryFileName
Output: the encrypted text (string result)
*/
string SubstitutionText::encrypt(string& text, string dictionaryFileName)
{
	string result = ""; //string for the result.
	string alphabet; //string for the regular alphabet.
	string cipherAlphabet; //string for the cipher alphabet.
	char ch; //char for the current letter, when extracting the file to strings.
	ifstream cipherFile; //file reading variable for the dictionary file.
	
	cipherFile.open(dictionaryFileName); //opening the dictionary file.
	
	//running until the end of the file.
	while (cipherFile)
	{
		//setting the first char to alphabet (regular)
		cipherFile.get(ch);
		alphabet += ch;
		//skipping (',')
		cipherFile.get(ch);
		//setting the third char to cipherAlphabet (cipher)
		cipherFile.get(ch);
		cipherAlphabet += ch;
		//skipping ('\n')
		cipherFile.get(ch);
		
	}

	cipherFile.close(); //closing the dictionary file.

	//looping for each char in the text string.
	for (int i = ZERO; i < text.length(); i++)
	{
		//if the current char is an alphabetic letter, and it is a lower letter, encrypting it and adding it to the result.
		if (isalpha(text[i]) && islower(text[i]))
		{
			result += cipherAlphabet[alphabet.find(text[i])];
		}

		//if the current char is a space (' '), a dot ('.'), or a comma (','), adding it as is to the result.
		else if (text[i] == ' ' || text[i] == '.' || text[i] == ',')
		{
			result += text[i];
		}
	}

	//updating text to the result (reference variable)
	text = result;
	//returning the result.
	return result;
}

/*
Static function to decrypt a given text, in Substitution cipher with the given cipher alphabet file.
Input: string& text, string dictionaryFileName
Output: the decrypted text (string result)
*/
string SubstitutionText::decrypt(string& text, string dictionaryFileName)
{
	string result = ""; //string for the result.
	string alphabet; //string for the regular alphabet.
	string cipherAlphabet; //string for the cipher alphabet.
	char ch; //char for the current letter, when extracting the file to strings.
	ifstream cipherFile; //file reading variable for the dictionary file.

	cipherFile.open(dictionaryFileName); //opening the dictionary file.

	//running until the end of the file.
	while (cipherFile)
	{
		//setting the first char to alphabet (regular)
		cipherFile.get(ch);
		alphabet += ch;
		//skipping (',')
		cipherFile.get(ch);
		//setting the third char to cipherAlphabet (cipher)
		cipherFile.get(ch);
		cipherAlphabet += ch;
		//skipping ('\n')
		cipherFile.get(ch);

	}

	cipherFile.close(); //closing the dictionary file.

	//looping for each char in the text string.
	for (int i = ZERO; i < text.length(); i++)
	{
		//if the current char is an alphabetic letter, and it is a lower letter, decrypting it and adding it to the result.
		if (isalpha(text[i]) && islower(text[i]))
		{
			result += alphabet[cipherAlphabet.find(text[i])];
		}

		//if the current char is a space (' '), a dot ('.'), or a comma (','), adding it as is to the result.
		else if (text[i] == ' ' || text[i] == '.' || text[i] == ',')
		{
			result += text[i];
		}
	}

	//updating text to the result (reference variable)
	text = result;
	//returning the result.
	return result;
}

/*
Function to encrypt the _text field of a SubstitutionText object, in Substitution cipher with the given cipher alphabet file.
Input: none
Output: the encrypted _text field, or the current _text field if it is already encrypted. (string)
*/
string SubstitutionText::encrypt()
{
	//checking if the object's text field is already encrypted. (entering if not)
	if (!_isEncrypted)
	{
		_isEncrypted = true;
		return encrypt(_text, _dictionaryFileName);
	}
	//if the text is already encrypted, returning it as is.
	return _text;
}

/*
Function to decrypt the _text field of a SubstitutionText object, in Substitution cipher with the given cipher alphabet file.
Input: none
Output: the decrypted _text field, or the current _text field if it is already decrypted. (string)
*/
string SubstitutionText::decrypt()
{
	//checking if the object's text field is encrypted. (entering if it is)
	if (_isEncrypted)
	{
		_isEncrypted = false;
		return decrypt(_text, _dictionaryFileName);
	}
	//if the text is already decrypted, returning it as is.
	return _text;
}

/*
OverLoading for the "<<" operator to output stream: the type of text object, and the text field.
Input: ostream& output (where to output to), const SubstitutionText& text (the object with the text to output)
Output: the object's type and text field (outputed using ostream& output).
*/
ostream& operator<<(ostream& output, const SubstitutionText& text)
{
	output << "Substitution\n\n" << text.getText();
	return output;
}
