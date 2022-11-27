#include "CaesarText.h"

#define KEY 3

CaesarText::CaesarText(string text) : ShiftText(text, KEY){}

CaesarText::~CaesarText()
{
    ShiftText::~ShiftText();
}

string CaesarText::encrypt(string& text)
{
    return ShiftText::encrypt(text, KEY);
}

string CaesarText::decrypt(string& text)
{
    return ShiftText::decrypt(text, KEY);
}

string CaesarText::encrypt()
{
    return ShiftText::encrypt();
}

string CaesarText::decrypt()
{
    return ShiftText::decrypt();
}