#include "pch.h"
#include "CppUnitTest.h"
#include<sstream>
#include "..\OPPO\Date.h"
#include "..\OPPO\Income.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace IncomeTest
{
	TEST_CLASS(IncomeTest)
	{
	public:
		
		TEST_METHOD(validValueTest)
		{
			income x;

			x.CorrectValue(3200);
		}

		TEST_METHOD(validDateTest) {
			DateStruct date;

			std::string dt = "17.09.21";

			date.CorrectDate(dt);
		}

		TEST_METHOD(validDateReadTest) {
			DateStruct date;

			std::string dt = "17.09.21";

			date.readDate(dt);
		}

		TEST_METHOD(validDatePrintTest) {
			DateStruct date;

			date.setDD(12);
			date.setMM(12);
			date.setYY(21);

			std::string dt = "Дата: 12.12.21";

			std::stringstream x;
			date.printDate(x);
			Assert::AreEqual(x.str(), dt);
		}

		TEST_METHOD(validIncomeReadTest) {
			income inc;

			std::stringstream f("");

			std::vector<income> ivec;
			
			try {
				inc.readIncome(f, ivec);
			}
			catch (const std::runtime_error& message) {
				return;
			}

			Assert::Fail();
		}

		TEST_METHOD(validIncomePrintTest) {
			income inc;
			DateStruct date;
			std::vector<income> ivec;

			date.setDD(12);
			date.setMM(12);
			date.setYY(21);

			inc.setDate(date);

			inc.setSum(3200);
			inc.setSource("Source1");

			std::string res = "Дата: 12.12.21 Источник дохода: Source1 Сумма:  3200\n";

			std::stringstream x;
			inc.print(x);
			Assert::AreEqual(x.str(), res);
		}

		TEST_METHOD(validIsLeapYear) {
			DateStruct date;

			date.isLeapYear(2024);
		}

		TEST_METHOD(validCorrectFunction) {
			DateStruct date;

			date.Correct(12, 12, 12);
		}

		TEST_METHOD(invalidCorrectFunction) {
			DateStruct date;

			try {
				date.Correct(-12, 22, 9);
			}
			catch (const std::runtime_error& message) {
				return;
			}

			Assert::Fail();
		}

		TEST_METHOD(invalidIsLeapYear) {
			try {
				DateStruct date;
				date.isLeapYear(-2019);
			}
			catch (const std::runtime_error& message) {
				return;
			}

			Assert::Fail();
		}

		TEST_METHOD(invalidValueTest)
		{

			try {
				income x;
				x.CorrectValue(-3200);
			}
			catch (const std::runtime_error& message) {
				return;
			}

			Assert::Fail();
		}

		TEST_METHOD(invalidDateTest)
		{
			try {
				DateStruct date;

				std::string d = "92.23.22";

				date.CorrectDate(d);
			}
			catch (const std::runtime_error& message) {
				return;
			}

			Assert::Fail();
		}

		TEST_METHOD(invalidDateReadTest) {
			DateStruct date;

			std::string d = "12.12.13";

			date.readDate(d);
		}

		TEST_METHOD(invalidDatePrintTest) {
			DateStruct date;
			date.setDD(13);
			date.setMM(12);
			date.setYY(21);

			std::string d = "Дата: 12.12.21";

			std::stringstream x;
			date.printDate(x);
			Assert::AreNotEqual(x.str(), d);
		}

		TEST_METHOD(invalidIncomePrintTest) {
			income inc;
			DateStruct date;
			std::vector<income> ivec;

			date.setDD(13);
			date.setMM(12);
			date.setYY(21);

			inc.setDate(date);

			inc.setSum(3200);
			inc.setSource("Source2");
			
			std::string d = "Дата: 12.12.21 Источник дохода: 33.3 Сумма: 3200\n";

			std::stringstream x;
			inc.print(x);
			Assert::AreNotEqual(x.str(), d);
		}

	};
}

