#include "stdafx.h"
#include "CLI.h"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <windows.h>
#include <vector>
#include <sstream>
#include <regex>

using namespace std;

CLI::CLI() {
	cout << "Command Line Interface 1.0 " << endl << "(c)2018 PUT students. All rights reserved." << endl << endl;
	cout << currentPath();
	string userInput = "";
	string firstArgument = "";
	string secondArgument = "";
	string thirdArgument = "";

	while (true) {
		ShowConsoleCursor(true);
		
		getline(std::cin, userInput);
		if (userInput == "") {
			cout << currentPath();
			continue;
		}
		vector<string> splitResult = splitString(userInput);

		userInput = splitResult[0];
		if (splitResult.size() == 2) {
			firstArgument = splitResult[1];
		}
		else if (splitResult.size() == 3) {
			secondArgument = splitResult[2];
		}
		else if (splitResult.size() == 4) {
			thirdArgument = splitResult[3];
		}

		switch (inputs(userInput))
		{
		case HELP:
			printHelp();
			break;
		case CD:
			changeDirectory(firstArgument);
			break;
		case DIR:
			break;
		case PS:
			break;
		default:
			printResult("Nie ma takiego polecenia");
			break;
		}

	}
}

CLI::~CLI() {}

void CLI::ShowConsoleCursor(bool showFlag) {
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);
}

string CLI::currentPath() {
	char buf[256];
	GetCurrentDirectoryA(256, buf);
	return string(buf) + '\\';
}

vector<string> CLI::splitString(string toSplit) {
	string buf;                 // Have a buffer string
	stringstream ss(toSplit);       // Insert the string into a stream
	vector<string> tokens; // Create vector to hold our words
	while (ss >> buf)
		tokens.push_back(buf);

	return tokens;
}

INPUTS CLI::inputs(string input) {
	if (input == "help") return HELP;
	else if (input == "cd") return CD;
	else if (input == "dir") return DIR;
	else if (input == "ps") return PS;
}

void CLI::printLine(string userInput) {
	cout << currentPath() + userInput << endl;
	cout << currentPath();
}

void CLI::printResult(string result) {
	cout << result << endl << endl;
	cout << currentPath();
}

void CLI::printHelp() {
	cout << "HELP HELP HELP HELP HELP HELP HELP HELP" << endl;
	cout << currentPath();
}

void CLI::changeDirectory(string parameter) {
	if (parameter == "..") {
		printResult("hura zmieniono direktora");
	}
	else {
		printResult("Nie rozpoznano argumentu");
	}
}

void CLI::dir() {
	system("dir");
	printResult("");
}

void CLI::ps() {
	system("tasklist");
	printResult("");
}