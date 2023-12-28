#pragma once
#include<fstream>
#include<vector>

#include"date.h"

struct income {
private:
	DateStruct Date;
	std::string source;
	int sum = 0;
public:

	std::string getSource();
	int getSum();
	DateStruct getDate();

	void setSum(int value);
	void setSource(std::string &val);
	void setDate(DateStruct date);


	static income createFromStream(std::istream& in);

	void print(std::ostream& out);

	void readIncome(std::istream& file, std::vector<income>& pvec);

	void printIncome(std::vector<income>& pvec, std::ostream& out);

	void CorrectValue(int sum);
};