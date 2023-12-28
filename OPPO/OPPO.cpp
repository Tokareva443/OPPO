// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include <iostream>
#include<fstream>
#include<vector>
#include<string>
#include<vld.h>
#include"date.h"
#include"Income.h"

int main()
{
	setlocale(LC_ALL, "Ru");

	std::ifstream file("test.txt");

	std::vector<income> pvec;

	income data;

	std::string error;

	try {

		data.readIncome(file, pvec);
	}

	catch (std::runtime_error& errorMessage) {
		error = errorMessage.what();
	}

	data.printIncome(pvec, std::cout);

	std::cout << error;
	return 0;
}