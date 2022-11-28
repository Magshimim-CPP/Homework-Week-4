#include "Menu.h"

//MAIN CODE
int main()
{
	//stating main code variables.
	string userString;
	bool exitMenu = false;
	int menuChoice;

	//looping until the user chooses to exit (option 4)
	while (!exitMenu)
	{
		cout << MENU_OPTIONS; //Printing the main menu
		cin >> menuChoice; //Taking input for user's choice
		
		MenuActions::checkInput(menuChoice); //checking the validity of the input.

		//PICKING ACTION ACCORDING TO THE USER'S CHOICE:
		switch (menuChoice)
		{

		case (STRING_CIPHER): //OPTION 1 - STRING
			
			cout << STR_INPUT; //user instructions
			getchar(); //(cleaning the buffer before taking input).
			getline(cin, userString); //getting user string input
			MenuActions::stringCipher(userString); //sending the user's string to the string actions menu function (stringCipher(string& userString)).
			break;

		case (FILE_CIPHER): //OPTION 2 - FILE

			MenuActions::fileCipher(); //entering the file actions menu function (fileCipher()).
			break;

		case (NUM_OF_TEXTS): //OPTION 3 - NUM OF TEXTS CREATED
			cout << GREEN;
			NUM_OF_OBJECTS;
			cout << RESET_COLOR;
			break;

		case (EXIT): //OPTION 4 - EXIT
			cout << GREEN;
			cout << EXIT_MESSAGE;
			cout << RESET_COLOR;
			exitMenu = true;
			break;

		default: //DEFAULT - INPUT WAS OUT OF RANGE
			cout << RED;
			cout << RANGE_ERROR << endl;
			cout << RESET_COLOR;
		}
	}
}


/*
Static function for option 1 of the main menu (Encrypt/Decrypt a string). String menu and actions with user interface.
Input: string& userString (reference variable)
Output: none
*/
void MenuActions::stringCipher(string& userString)
{
	//stating variables at the start of the function.
	int stringMenuChoice;
	int key = NO_KEY;

	cout << CIPHER_OPTIONS; //Printing the string actions menu
	cin >> stringMenuChoice; //Taking input for user's choice

	checkInput(stringMenuChoice); //checking the validity of the input.

	//If user's choice input was out of the options range, printing error and taking new input.
	while (stringMenuChoice < MIN_OPTION || stringMenuChoice > MAX_STRING_OPTION)
	{
		cout << RED;
		cout << RANGE_ERROR << endl;
		cout << RESET_COLOR;
		cin >> stringMenuChoice;
		checkInput(stringMenuChoice); //checking the validity of the input.
	}

	//Entering condition if the user chose shift cipher, in order to take key input.
	if (stringMenuChoice == ENC_SHIFT || stringMenuChoice == DEC_SHIFT)
	{
		cout << KEY_INPUT;
		cin >> key;

		checkInput(key); //checking the validity of the input.

		//if key is outside the range of possible shift keys (0-26), printing arror and taking new input.
		while (key < MIN_KEY || key > MAX_KEY)
		{
			cout << RED;
			cout << KEY_ERROR;
			cout << RESET_COLOR;
			cin >> key;
			checkInput(key); //checking the validity of the input.
		}
	}

	//Green success message to display the users encrypted/decrypted string.
	cout << GREEN;
	cout << "\nSUCCESS: Your string is -  "; //(string itself is printed in the switch-case slot)

	//PICKING ACTION ACCORDING TO THE USER'S CHOICE:
	switch (stringMenuChoice)
	{
		case (ENC_SHIFT): //Shift Text Encryption
			cout << ShiftText::encrypt(userString, key) << endl;
			break;
		case (DEC_SHIFT): //Shift Text Decryption
			cout << ShiftText::decrypt(userString, key) << endl;
			break;
		case (ENC_CAESAR): //Caesar Text Encryption
			cout << CaesarText::encrypt(userString) << endl;
			break;
		case (DEC_CAESAR): //Caesar Text Decryption
			cout << CaesarText::decrypt(userString) << endl;
			break;
		case (ENC_SUBSTITUTION): //Substitution Text Encryption
			cout << SubstitutionText::encrypt(userString, DICT) << endl;
			break;
		case (DEC_SUBSTITUTION): //Substitution Text Decryption
			cout << SubstitutionText::decrypt(userString, DICT) << endl;
			break;
	}
	cout << RESET_COLOR; //reseting the color (from green back to white).
}


/*
Static function for option 2 of the main menu (Encrypt/Decrypt a .txt file). Files menu and actions with user interface.
Input: none
Output: none
*/
void MenuActions::fileCipher()
{
	//stating variables at the start of the function.
	string fileName;
	string fileStr;
	int toSave;

	
	cout << FILE_INPUT << endl; //user instructions
	getchar(); //(cleaning buffer)
	getline(cin, fileName); //taking file name input

	fileStr = FileHelper::readFileToString(fileName); //reading the file's content to a string.

	//entering condition if the file was found and it's content is now on the string.
	if (fileStr != FILE_NOT_FOUND)
	{
		MenuActions::stringCipher(fileStr); //sending the string with the file's content to the string actions menu for cipher encryption/decryption.

		//asking the user if he would like to save a file with the result.
		cout << ASK_SAVE << endl;
		cin >> toSave; //taking input

		checkInput(toSave); //checking the validity of the input.

		//entering condition if the user chose to save a file with the result
		if (toSave == ZERO)
		{
			FileHelper::saveTextInFile(fileStr, OUTPUT_FILE); //saving the string to a file (using saveTextInFile(string text, string outputFileName) from FileHelper).
			cout << GREEN;
			cout << SAVE_SUCCESS; //printing green success message to the user.
			cout << RESET_COLOR;
		}
	}

	//if file was not found, printing the error in the string to the user (file not found).
	else
	{
		cout << RED;
		cout << fileStr << endl;
		cout << RESET_COLOR;
	}

}


/*
Static function to check input errors (cin fail), in case user enterd a char to int etc..
Input: int& num (reference variable)
Output: none
*/
void MenuActions::checkInput(int& num)
{
	if (cin.fail()) //checking if there is a cin fail (input error)
	{
		num = ERROR_NUMBER; //setting num to ERROR_NUMBER (-1) in order to repeat the option choice in the main code.
		cin.clear(); //clearing the input buffer
		cin.ignore(CHAR_MAX, '\n'); //ignoring cin input until '\n' (new line).
	}
}