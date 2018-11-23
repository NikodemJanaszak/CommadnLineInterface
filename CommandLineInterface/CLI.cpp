#include "stdafx.h"
#include "CLI.h"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <windows.h>
#include <vector>
#include <sstream>
#include <regex>
#include <stdio.h>

using namespace std;

CLI::CLI() {

	cout << "Command Line Interface 1.0 " << endl << "(c)2018 PUT students. All rights reserved." << endl << endl;
	cout << currentPath();

	while (true) {
		ShowConsoleCursor(true);
		
		getline(std::cin, userInput);
		if (userInput == "") {
			cout << currentPath();
			continue;
		}
		splitResult = splitString(userInput);

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

		switch (inputs(userInput)) {
		case HELP:
			printHelp();
			break;
		case CD:
			changeDirectory(firstArgument);
			break;
		case DIR:
			dir();
			break;
		case TASKS:
			tasks();
			break;
		case MYLOG:
				mylog();
			break;
		case EXIT:
			if (askExit()) goto closer;
			break;
		default:
			printResult("Nie ma takiego polecenia");
			break;
		}
	}
closer:
	printf("Zamykanie systemu... ");
	counter();

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
	else if (input == "tasks") return TASKS;
	else if (input == "mylog") return MYLOG;
	else if (input == "exit") return EXIT;
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

void CLI::tasks() {
	system("tasklist");
	printResult("");
}

void CLI::mylog() {
	system("echo %USERNAME%");
	printResult("");
}

int CLI::askExit() {
	char ask;
	cout << "Czy na pewno chcesz zamknac system? (t/n): ";
	cin >> ask;
	if (ask == 't') return 1;
	else return 0;
}

void CLI::counter() {
	for (int i = 3; i >= 1; i--)
	{
		cout << " " << i;
		Sleep(1000);
	}
	
}