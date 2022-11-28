#include "ShiftText.h"

/*
Constructor function for a ShiftText object (also using PlainText constructor).
Input: string text, int key
Output: none
*/
ShiftText::ShiftText(string text, int key) : PlainText(text)
{
	_key = key;
    _text = encrypt(text, key); //Setting the _text field to the encryption of the given string (text).
    _isEncrypted = true;
}

/*
Destructor function for a ShiftText object.
Input: none
Output: none
*/
ShiftText::~ShiftText()
{
    //activating PlainText fields destructor.
    PlainText::~PlainText();
    //setting key to 0.
    _key = ZERO;
}

/*
Static function to encrypt a given text, in shift cipher with the given key.
Input: string& text, int key
Output: the encrypted text (string result)
*/
string ShiftText::encrypt(string& text, int key)
{
    //creating a string for the result.
    string result = "";

    //looping for each char in the text string.
    for (int i = ZERO; i < text.length(); i++)
    {
        //if the current char is an alphabetic letter, and it is a lower letter, encrypting it and adding it to the result.
        if (isalpha(text[i]) && islower(text[i]))
        {
            result += encryptLetter(text, i, key);
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
Static function to decrypt a given text, in shift cipher with the given key.
Input: string& text, int key
Output: the decrypted text (string result)
*/
string ShiftText::decrypt(string& text, int key)
{
    //creating a string for the result.
    string result = "";

    //looping for each char in the text string.
    for (int i = ZERO; i < text.length(); i++)
    {
        //if the current char is an alphabetic letter, and it is a lower letter, decrypting it and adding it to the result.
        if (isalpha(text[i]) && islower(text[i]))
        {
            result += decryptLetter(text, i, key);
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
Function to encrypt the _text field of a ShiftText object, in shift cipher with the key field as encryption key.
Input: none
Output: the encrypted _text field, or the current _text field if it is already encrypted.
*/
string ShiftText::encrypt()
{
    //checking if the object's text field is already encrypted. (entering if not)
    if (!_isEncrypted)
    {
        _isEncrypted = true;
        return encrypt(_text, _key);
    }
    //if the text is already encrypted, returning it as is.
    return _text;
}

/*
Function to decrypt the _text field of a ShiftText object, in shift cipher with the key field as decryption key.
Input: none
Output: the decrypted _text field, or the current _text field if it is already decrypted.
*/
string ShiftText::decrypt()
{
    //checking if the object's text field is encrypted. (entering if it is)
    if (_isEncrypted)
    {
        _isEncrypted = false;
        return decrypt(_text, _key);
    }
    //if the text is already decrypted, returning it as is.
    return _text;
}

/*
Function encrypt's a letter in shift cipher format. (self added, not requested)
Input: const string text, const int place, const int key
Output: the encrypted letter (char)
*/
char ShiftText::encryptLetter(const string text, const int place, const int key)
{
    return char(int(text[place] + key - 97) % 26 + 97);
}

/*
Function decrypt's a letter in shift cipher format. (self added, not requested)
Input: const string text, const int place, const int key
Output: the decrypted letter (char)
*/
char ShiftText::decryptLetter(const string text, const int place, const int key)
{
    return char((int(text[place] - key - 97) % 26 + 26) % 26 + 97);
}

/*
OverLoading for the "<<" operator to output stream: the type of text object, and the _text field.
Input: ostream& output (where to output to), const ShiftText& text (the object with the text to output)
Output: the object's type and text field (outputed using ostream& output).
*/
ostream& operator<<(ostream& output, const ShiftText& text)
{
    output << "Shift\n\n" << text.getText();
    return output;
}

