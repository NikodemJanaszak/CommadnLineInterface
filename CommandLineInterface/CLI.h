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

class CLI{
public:
	CLI();
	~CLI();
	void printLine(string userInput);
	void ShowConsoleCursor(bool showFlag);
	void printResult(string result);
	void changeDirectory(string parameter);
	string currentPath();
	vector<string> splitString(string toSplit);
	void dir();
	void ps();

private:

};

#endif