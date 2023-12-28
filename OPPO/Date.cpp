// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include "date.h"
#include<string>
#include<iostream>

void DateStruct::readDate(std::string& dateStr) {
    if (dateStr[2] == '.' && dateStr[5] == '.') {
        int d = stoi(dateStr.substr(0, 2));
        int m = stoi(dateStr.substr(3, 5));
        int y = stoi(dateStr.substr(6, 8));

        dd = d;
        mm = m;
        yy = y;
    }
    else throw std::runtime_error("Введена неверная дата!");
}

void DateStruct::printDate(std::ostream& out) {
    out << "Дата: " << dd << '.' << mm << '.' << yy;
}

int DateStruct::getDD() {
    return dd;
}

int DateStruct::getMM() {
    return mm;
}

int DateStruct::getYY() {
    return yy;
}

void DateStruct::setDD(int value) {
    Correct(value, 12, 12);
    dd = value;
}

void DateStruct::setMM(int value) {
    Correct(12, value, 12);
    mm = value;
}

void DateStruct::setYY(int value) {
    Correct(12, 12, value);
    yy = value;
}


bool DateStruct::isLeapYear(int year) {
    if (year < 0) throw std::runtime_error("Неверно указан год!");
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

void DateStruct::Correct(int day, int month, int year) {
    int maxDays = 31;
    switch (month) {
    case 2:
        maxDays = isLeapYear(year) ? 29 : 28;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        maxDays = 30;
        break;
    }

    if (day < 1 || !(day <= maxDays)) throw std::runtime_error("День ввёден неверно!");
    if (month < 1 || month > 12) throw std::runtime_error("Месяц ввёден неверно!");
    if (year < 0 || year > 99) throw std::runtime_error("Год ввёден неверно!");
}

void DateStruct::CorrectDate(std::string& dateStr) {
    if ((dateStr.length() > 8 || dateStr.length() <= 7) || !(dateStr[2] == '.' && dateStr[5] == '.')) throw std::runtime_error("Дата введена неверно!");
    int d = stoi(dateStr.substr(0, 2));
    int m = stoi(dateStr.substr(3, 5));
    int y = stoi(dateStr.substr(6, 8));

    Correct(d, m, y);
}