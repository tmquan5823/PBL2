#pragma once
#include<iostream>
#include<ctime>
using namespace std;

class Date{
    private:
        int day;
        int month;
        int year;
    public:
        Date();
        Date(int, int, int);
        ~Date();
        int getDay();
        int getMonth();
        int getYear();
        bool isLeapYear(const int&);
        Date localDate();
        int monthDays();
        void nextDay();
        bool operator > (const Date&);
        bool operator >= (const Date&);
        bool operator < (const Date&);
        bool operator <= (const Date&);
        bool operator == (const Date&);
        const Date& operator = (const Date&);
        friend istream& operator>>(istream &i, Date&);
        friend ostream& operator<<(ostream &o, const Date&);
};