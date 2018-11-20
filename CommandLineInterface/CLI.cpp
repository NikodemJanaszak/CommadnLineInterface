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
	cout << "Microsoft Windows [Version 10.0.17134.407] " << endl << "(c)2018 Microsoft Corporation.All rights reserved." << endl << endl;
	cout << currentPath();
	string userInput = "";
	string firstArgument = "";

	while (true) {
		ShowConsoleCursor(true);
		getline(std::cin, userInput);
		vector<string> splitResult = splitString(userInput);
		userInput = splitResult[0];

		if (splitResult.size() > 1) {
			firstArgument = splitResult[1];
		}

		if (userInput == "cd") {
			changeDirectory(firstArgument);
		}
		else if (userInput == "dir") {
			dir();
		}
		else if (userInput == "ps") {
			ps();
		}
		else if (userInput == "dwa") {
			printResult(userInput);
		}
		else if (userInput == "dwa") {
			printResult(userInput);
		}
		else if (userInput == "dwa") {
			printResult(userInput);
		}
		else if (userInput == "dwa") {
			printResult(userInput);
		}
	}
}

CLI::~CLI() {}

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

void CLI::printLine(string userInput) {
	cout << currentPath() + userInput << endl;
	cout << currentPath();
}

vector<string> CLI::splitString(string toSplit) {
	string buf;                 // Have a buffer string
	stringstream ss(toSplit);       // Insert the string into a stream
	vector<string> tokens; // Create vector to hold our words
	while (ss >> buf)
		tokens.push_back(buf);

	return tokens;
}

void CLI::printResult(string result) {
	cout << result << endl << endl;
	cout << currentPath();
}

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