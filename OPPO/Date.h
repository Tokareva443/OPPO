#pragma once
#pragma once
#include<string>
struct DateStruct {
private:
	int dd = 0, mm = 0, yy = 0;
public:

	int getDD();
	int getMM();
	int getYY();

	void setDD(int value);
	void setMM(int value);
	void setYY(int value);


	void readDate(std::string& dateStr);

	void printDate(std::ostream& out);

	void CorrectDate(std::string& dateStr);

	void Correct(int dd, int mm, int yy);

	bool isLeapYear(int year);
};