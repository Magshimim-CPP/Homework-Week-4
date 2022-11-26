#include "SubstitutionText.h"

#define ALPHABET "abcdefghijklmnopqrstuvwxyz"

SubstitutionText::SubstitutionText(string text, string dictionaryFileName) : PlainText(text)
{
	_dictionaryFileName = dictionaryFileName;
	_text = encrypt(text, dictionaryFileName);
	_isEncrypted = true;
}

SubstitutionText::~SubstitutionText()
{
	PlainText::~PlainText();
	_dictionaryFileName = "";
}

string SubstitutionText::encrypt(string& text, string dictionaryFileName)
{
	string result = "";
	string dict;
	char ch;
	string alphabet = ALPHABET;
	ifstream key;
	key.open("dictionary.csv");
	
	while (key)
	{
		key.get(ch);
		key.get(ch);
		key.get(ch);
		dict += ch;
		key.get(ch);
		
	}

	for (int i = 0; i < text.length(); i++)
	{
		if (isalpha(text[i]) && islower(text[i]))
		{
			result += dict[alphabet.find(text[i])];
		}
		else if (text[i] == ' ' || text[i] == '.' || text[i] == ',')
		{
			result += text[i];
		}
	}
	text = result;
	return result;
}

string SubstitutionText::decrypt(string& text, string dictionaryFileName)
{
	string result = "";
	char ch;
	string dict;
	string alphabet = ALPHABET;
	ifstream key;
	key.open("dictionary.csv");

	while (key)
	{
		key.get(ch);
		key.get(ch);
		key.get(ch);
		dict += ch;
		key.get(ch);

	}

	for (int i = 0; i < text.length(); i++)
	{
		if (isalpha(text[i]) && islower(text[i]))
		{
			result += alphabet[dict.find(text[i])];
		}
		else if (text[i] == ' ' || text[i] == '.' || text[i] == ',')
		{
			result += text[i];
		}
	}
	text = result;
	return result;
}

string SubstitutionText::encrypt()
{
	if (!_isEncrypted)
	{
		_isEncrypted = true;
		return encrypt(_text, _dictionaryFileName);
	}
	return _text;
}

string SubstitutionText::decrypt()
{
	if (_isEncrypted)
	{
		_isEncrypted = false;
		return decrypt(_text, _dictionaryFileName);
	}
	return _text;
}
