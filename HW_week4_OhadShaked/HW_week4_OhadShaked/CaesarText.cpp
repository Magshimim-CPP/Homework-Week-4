#include "CaesarText.h"

/*
Constructor function for a CaesarText object (using ShiftText constructor).
Input: string text
Output: none
*/
CaesarText::CaesarText(string text) : ShiftText(text, KEY){}

/*
Destructor function for a CaesarText object (activates ShiftText destructor).
Input: none
Output: none
*/
CaesarText::~CaesarText()
{
    ShiftText::~ShiftText();
}

/*
Static function to encrypt a given text in Caesar cipher (with the const key 3).
Input: string& text (reference variable).
Output: the encrypted text (string)
*/
string CaesarText::encrypt(string& text)
{
    return ShiftText::encrypt(text, KEY);
}

/*
Static function to decrypt a given text in Caesar cipher (with the const key 3).
Input: string& text (reference variable).
Output: the decrypted text (string)
*/
string CaesarText::decrypt(string& text)
{
    return ShiftText::decrypt(text, KEY);
}

/*
Function to encrypt the _text field of a CaesarText object, in Caesar cipher (with the const key 3).
Input: none
Output: the encrypted _text field, or the current _text field if it is already encrypted. (string)
*/
string CaesarText::encrypt()
{
    return ShiftText::encrypt();
}

/*
Function to decrypt the _text field of a CaesarText object, in Caesar cipher (with the const key 3).
Input: none
Output: the decrypted _text field, or the current _text field if it is already decrypted. (string)
*/
string CaesarText::decrypt()
{
    return ShiftText::decrypt();
}

/*
OverLoading for the "<<" operator to output stream: the type of text object, and the text field.
Input: ostream& output (where to output to), const CaesarText& text (the object with the text to output)
Output: the object's type and text field (outputed using ostream& output).
*/
ostream& operator<<(ostream& output, const CaesarText& text)
{
    output << "Caesar\n\n" << text.getText();
    return output;
}