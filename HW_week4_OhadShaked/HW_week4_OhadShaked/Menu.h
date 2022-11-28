#pragma once
#ifndef MENU_H
#define MENU_H

//Using iostream, string, and all of our header files.
#include <iostream>
#include <string>
#include "PlainText.h"
#include "CaesarText.h"
#include "FileHelper.h"
#include "ShiftText.h"
#include "SubstitutionText.h"

//Using specific functions from the std namespace.
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::getline;

//Texts for user interface (menu instructions).
#define MENU_OPTIONS "\nMAIN MENU OPTIONS:\n1 - Encrypt/Decrypt a string\n2 - Encrypt/Decrypt a .txt file\n3 - Number of texts created in the program\n4 - Exit\nYour choice: "
#define CIPHER_OPTIONS "\nPlease select the cipher you want for encryption/decryption\nPress 1 for - Shift encryption\nPress 2 for - Shift decryption\nPress 3 for - Caesar encryption\nPress 4 for - Caesar decryption\nPress 5 for - Substitution encryption\nPress 6 for - Substitution decryption\nYour choice: "
#define RANGE_ERROR "\nERROR: Number of choice was out of the options range.\nPlease try again\n"
#define STR_INPUT "\nPlease enter a string to preform the action on:  "
#define FILE_INPUT "\nPlease enter a file's name to preform the action on (for example: shimshon.txt):  "
#define KEY_INPUT "\nPlease enter a key for the shift encryption:  "
#define KEY_ERROR "\nERROR: Key was out of range (0 - 26).\nPlease select again:  "
#define DICT "dictionary.csv"
#define OUTPUT_FILE "outputText.txt"
#define ASK_SAVE "\nWould you like to save a file with the result?\n0 - YES\nElse - NO\n\nYour choice:  "
#define SAVE_SUCCESS "Successfully saved the result at 'outputText.txt'\n"
#define NUM_OF_OBJECTS cout << "Number of text objects created in the program so far: " << PlainText::numOfTexts << ".\nWe are using static functions and not creating new text objects, so the number should be 0." << endl
#define EXIT_MESSAGE "\nThank you for using my cipher program\nGoodbye!\n"

//Main menu options.
#define STRING_CIPHER 1
#define FILE_CIPHER 2
#define NUM_OF_TEXTS 3
#define EXIT 4

//String menu options.
#define ENC_SHIFT 1
#define DEC_SHIFT 2
#define ENC_CAESAR 3
#define DEC_CAESAR 4
#define ENC_SUBSTITUTION 5
#define DEC_SUBSTITUTION 6
#define MIN_OPTION 1
#define MAX_STRING_OPTION 6

//Shift cipher key starting value (-1, invalid, no key), max value (26) and min value (0)
#define NO_KEY -1
#define MIN_KEY 0
#define MAX_KEY 26

//File menu saving options.
#define PRINT_FILE 1
#define SAVE_FILE 2

//Colors for program look's
#define CYAN "\033[1;1;36m"
#define GREEN "\033[1;32m"
#define RED "\033[1;31m" 
#define RESET_COLOR "\033[0m"

//Defining constant values for ZERO (0), and ERROR_NUMBER (-1).
#define ZERO 0
#define ERROR_NUMBER -1


//Menu Actions class
class MenuActions
{
//Setting public functions for the MenuActions class.
public:
	static void stringCipher(string& userString); //Static function for option 1 of the main menu (Encrypt/Decrypt a string). String menu and actions with user interface.
	static void fileCipher(); //Static function for option 2 of the main menu (Encrypt/Decrypt a .txt file). Files menu and actions with user interface.
	static void checkInput(int& num); //Static function to check input errors (cin fail), in case user enterd a char to int etc..
};

#endif