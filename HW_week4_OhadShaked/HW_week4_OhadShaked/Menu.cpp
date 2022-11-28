#include "Menu.h"

int main()
{
	string userString;
	bool exitMenu = false;
	int menuChoice;

	while (!exitMenu)
	{
		cout << MENU_OPTIONS;
		cin >> menuChoice;
		
		MenuActions::checkInput(menuChoice);

		switch (menuChoice)
		{

		case (STRING_CIPHER):
			cout << STR_INPUT;
			getchar();
			getline(cin, userString);
			MenuActions::stringCipher(userString);
			break;
		case (FILE_CIPHER):
			MenuActions::fileCipher();
			break;
		case (NUM_OF_TEXTS):
			cout << GREEN;
			NUM_OF_OBJECTS;
			cout << RESET_COLOR;
			break;
		case (EXIT):
			cout << GREEN;
			cout << EXIT_MESSAGE;
			cout << RESET_COLOR;
			exitMenu = true;
			break;
		default:
			cout << RED;
			cout << RANGE_ERROR << endl;
			cout << RESET_COLOR;
		}
	}
}




void MenuActions::stringCipher(string& userString)
{
	int stringMenuChoice;
	int key = NO_KEY;

	cout << CIPHER_OPTIONS;
	cin >> stringMenuChoice;

	checkInput(stringMenuChoice);

	while (stringMenuChoice < MIN_OPTION || stringMenuChoice > MAX_STRING_OPTION)
	{
		cout << RED;
		cout << RANGE_ERROR << endl;
		cout << RESET_COLOR;
		cin >> stringMenuChoice;
		checkInput(stringMenuChoice);
	}

	if (stringMenuChoice == ENC_SHIFT || stringMenuChoice == DEC_SHIFT)
	{
		cout << KEY_INPUT;
		cin >> key;

		checkInput(key);

		while (key < MIN_KEY || key > MAX_KEY)
		{
			cout << RED;
			cout << KEY_ERROR;
			cout << RESET_COLOR;
			cin >> key;
			checkInput(key);
		}
	}

	cout << GREEN;
	cout << "\nSUCCESS: Your string is -  ";

	switch (stringMenuChoice)
	{
		case (ENC_SHIFT):
			cout << ShiftText::encrypt(userString, key) << endl;
			break;
		case (DEC_SHIFT):
			cout << ShiftText::decrypt(userString, key) << endl;
			break;
		case (ENC_CAESAR):
			cout << CaesarText::encrypt(userString) << endl;
			break;
		case (DEC_CAESAR):
			cout << CaesarText::decrypt(userString) << endl;
			break;
		case (ENC_SUBSTITUTION):
			cout << SubstitutionText::encrypt(userString, DICT) << endl;
			break;
		case (DEC_SUBSTITUTION):
			cout << SubstitutionText::decrypt(userString, DICT) << endl;
			break;
	}
	cout << RESET_COLOR;
}

void MenuActions::fileCipher()
{
	string fileName;
	int toSave;
	string fileStr;

	cout << FILE_INPUT << endl;
	getchar();
	getline(cin, fileName);

	fileStr = FileHelper::readFileToString(fileName);

	if (fileStr != FILE_NOT_FOUND)
	{
		MenuActions::stringCipher(fileStr);

		cout << ASK_SAVE << endl;
		cin >> toSave;

		checkInput(toSave);

		if (toSave == ZERO)
		{
			FileHelper::saveTextInFile(fileStr, OUTPUT_FILE);
			cout << GREEN;
			cout << SAVE_SUCCESS;
			cout << RESET_COLOR;
		}
	}
	else
	{
		cout << RED;
		cout << fileStr << endl;
		cout << RESET_COLOR;
	}

}

void MenuActions::checkInput(int& num)
{
	if (cin.fail())
	{
		num = ERROR_NUMBER;
		cin.clear();
		cin.ignore(CHAR_MAX, '\n');
	}
}