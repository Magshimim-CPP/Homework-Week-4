#pragma once
#ifndef MENU_H
#define MENU_H

#include <iostream>
#include "PlainText.h"
#include "CaesarText.h"
#include "FileHelper.h"
#include "ShiftText.h"
#include "SubstitutionText.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::getline;

//Texts for user instructions (menus).
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

//String menu options.
#define ENC_SHIFT 1
#define DEC_SHIFT 2
#define ENC_CAESAR 3
#define DEC_CAESAR 4
#define ENC_SUBSTITUTION 5
#define DEC_SUBSTITUTION 6
#define MIN_OPTION 1
#define MAX_STRING_OPTION 6

#define PRINT_FILE 1
#define SAVE_FILE 2

//Main menu options.
#define STRING_CIPHER 1
#define FILE_CIPHER 2
#define NUM_OF_TEXTS 3
#define EXIT 4

//colors for program look's
#define CYAN "\033[1;1;36m"
#define GREEN "\033[1;32m"
#define RED "\033[1;31m" 
#define RESET_COLOR "\033[0m"

#define ZERO 0
#define ERROR_NUMBER -1
#define NO_KEY -1
#define MIN_KEY 0
#define MAX_KEY 26

class MenuActions
{
public:
	static void stringCipher(string& userString);
	static void fileCipher();
	static void checkIfDigit(int& num);
};
#endif