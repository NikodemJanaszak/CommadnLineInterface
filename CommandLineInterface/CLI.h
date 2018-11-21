#pragma once

#ifndef CLI_H
#define CLI_H

#include <iostream>
#include <stdlib.h>
#include <string>
#include <windows.h>
#include <vector>
#include <sstream>
#include <regex>

using namespace std;

enum INPUTS{
	HELP, CD, DIR, PS, EXIT
};

class CLI{
public:
	string userInput = "";
	string firstArgument = "";
	string secondArgument = "";
	string thirdArgument = "";
	vector<string> splitResult;

	CLI();
	~CLI();
	void printLine(string userInput);
	void ShowConsoleCursor(bool showFlag);
	INPUTS inputs(string userInput);
	void printResult(string result);
	void printHelp();
	void changeDirectory(string parameter);
	string currentPath();
	vector<string> splitString(string toSplit);
	void dir();
	void ps();
	int askExit();
	void counter();
private:

};

#endif