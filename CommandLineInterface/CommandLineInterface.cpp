// CommandLineInterface.cpp : Defines the entry point for the console application.
//
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


int main() {
	
	CLI *konsola = new CLI();


	system("pause");

	delete konsola;

    return 0;
}
