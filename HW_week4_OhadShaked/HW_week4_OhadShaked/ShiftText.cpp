#include "ShiftText.h"

ShiftText::ShiftText(string text, int key) : PlainText(text)
{
	_key = key;
    _text = encrypt(text, key);
    _isEncrypted = true;
}

ShiftText::~ShiftText()
{
    PlainText::~PlainText();
    _key = 0;
}

string ShiftText::encrypt(string& text, int key)
{
    string result = "";

    for (int i = 0; i < text.length(); i++)
    {

        if (isalpha(text[i]) && !isupper(text[i]))
        {
            result += encryptLetter(text, i, key);
        }

        else if (text[i] == ' ' || text[i] == '.' || text[i] == ',')
        {
            result += text[i];
        }
    }
    text = result;
    return result;
}

string ShiftText::decrypt(string& text, int key)
{
    string result = "";

    for (int i = 0; i < text.length(); i++)
    {

        if (isalpha(text[i]) && !isupper(text[i]))
        {
            result += decryptLetter(text, i, key);
        }

        else if (text[i] == ' ' || text[i] == '.' || text[i] == ',')
        {
            result += text[i];
        }
    }
    text = result;
    return result;
}

string ShiftText::encrypt()
{
    if (!_isEncrypted)
    {
        _isEncrypted = true;
        return encrypt(_text, _key);
    }
    return _text;
}

string ShiftText::decrypt()
{
    if (_isEncrypted)
    {
        _isEncrypted = false;
        return decrypt(_text, _key);
    }
    return _text;
}

char ShiftText::encryptLetter(string text, int place, int key)
{
    return char(int(text[place] + key - 97) % 26 + 97);
}

char ShiftText::decryptLetter(string text, int place, int key)
{
    return char((int(text[place] - key - 97) % 26 + 26) % 26 + 97);
}

