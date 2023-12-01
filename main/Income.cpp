#include<fstream>
#include<vector>
#include<string>
#include<iostream>

#include "Income.h"

income income::createFromStream(std::istream& in)
{
	income incomeData;

	std::string DATE;

	in >> DATE;

	std::string source;
	int sum = 0;

	in >> source;
	in >> sum;

	incomeData.CorrectValue(sum);
	incomeData.source = source;
	incomeData.sum = sum;
	
	incomeData.Date.CorrectDate(DATE);
	incomeData.Date.readDate(DATE);

	return incomeData;
}

void income::CorrectValue(int sum) {
	if (sum < 0) throw std::runtime_error("Неверно введена сумма!");
}

void income::print(std::ostream& out)
{
	Date.printDate(out);

	out << " Источник дохода: " << source << " Сумма:  " << sum << "\n";
}

void income::readIncome(std::istream& file, std::vector<income>& pvec) {
	while (!file.eof()) {
		income incomeData = income::createFromStream(file);
		pvec.push_back(incomeData);
	}
}

void income::printIncome(std::vector<income>& pvec, std::ostream& out) {
	for (auto& data : pvec) {
		data.print(out);
	}
}

std::string income::getSource() {
	return source;
}

int income::getSum() {
	return sum;
}

void income::setSource(std::string val) {
	source = val;
}

void income::setSum(int val) {
	CorrectValue(val);
	sum = val;
}

DateStruct income::getDate() {
	return Date;
}

void income::setDate(DateStruct date) {

	date.Correct(date.getDD(), date.getMM(), date.getYY());
	Date = date;
}