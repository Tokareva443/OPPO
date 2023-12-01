#include <iostream>
#include<fstream>
#include<vector>
#include<string>
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