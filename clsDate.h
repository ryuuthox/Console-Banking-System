#pragma warning(disable:4996)
#pragma once
#include <ctime>
#include <iostream>
#include <vector>
#include <string>

using namespace std;
class clsDate {
private:
    short year;
    short month;
    short day;


public:
    clsDate() {
        time_t t = time(0);
        tm* sTime = gmtime(&t);
        this->year = sTime->tm_year + 1900;
        this->month = sTime->tm_mon+1;
        this->day = sTime->tm_mday ;
    }

    static string numChar(char c, short n) {
        string s = "";
        for (int i = 0; i < n; i++) {
            s += c;
        }
        return s;
    }

    clsDate(short day, short month, short year) {
        this->year = year;
        this->month = month;
        this->day = day;
    }

    clsDate(string sdate) {
        clsDate date = convertStringDateIntoStruct(sdate);
        this->year = date.year;
        this->month = date.month;
        this->day = date.day;
    }

    clsDate(short ndays, short year) {
        clsDate date = dateFromNumberOfDays(ndays, year);
        this->year = date.year;
        this->month = date.month;
        this->day = date.day;
    }

    void setYear(short year) { this->year = year; }

    short getYear() { return this->year; }

    void setMonth(short month) { this->month = month; }

    short getMonth() { return this->month; }

    void setDay(short day) { this->day = day; }

    short getDay() { return this->day; }

    static void swap(short& a, short& b) {
        short temp = a;
        a = b;
        b = temp;
    }

    static void swapDates(clsDate d1, clsDate& d2) {
        swap(d1.day, d2.day);
        swap(d1.month, d2.month);
        swap(d1.year, d2.year);
    }

    static bool isLeapYear(clsDate date) { return isLeapYear(date.year); }

    bool isLeapYear() { return isLeapYear(*this); }

    static bool isLeapYear(short year) {
        return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
    }

    static int numberOfDaysInYear(clsDate date) {
        return isLeapYear(date) ? 366 : 365;
    }

    int numberOfDaysInYear() { return numberOfDaysInYear(*this); }

    static int numberOfHoursInYear(clsDate date) {
        return numberOfDaysInYear(date) * 24;
    }

    int numberOfHoursInYear() { return numberOfHoursInYear(*this); }

    static int numberOfMinutesInYear(clsDate date) {
        return numberOfHoursInYear(date) * 60;
    }

    int numberOfMinutesInYear() { return numberOfMinutesInYear(*this); }

    static int numberOfDaysInMonth(short month, short year) {

        if (month <= 0 || month > 12)
            return 0;

        short daysNumber[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        return month == 2 ? (isLeapYear(year) ? 29 : 28) : daysNumber[month - 1];
    }

    static int numberOfDaysInMonth(clsDate date) {
        return numberOfDaysInMonth(date.month, date.year);
    }

    int numberOfDaysInMonth() { return numberOfDaysInMonth(*this); }

    static void print(clsDate date) {
        cout <<getStringDate(date)<< endl;
    }
    void print() { print(*this); }

    static string getStringDate(clsDate date) {
        string d = to_string(date.day) + "/" + to_string(date.month) + "/" + to_string(date.year);
        return d;
    }

    string getStringDate() {
      return  getStringDate(*this);
    }

    clsDate convertStringDateIntoStruct(string dt) {
        short pos = 0;
        short spos = 0;
        vector<string> vDinfo;
        clsDate date;

        while ((spos = dt.find("/", pos)) != string::npos) {
            vDinfo.push_back(dt.substr(pos, spos - pos));
            pos = spos + 1;
        }
        vDinfo.push_back(dt.substr(pos));

        date.day = stoi(vDinfo[0]);
        date.month = stoi(vDinfo[1]);
        date.year = stoi(vDinfo[2]);

        return date;
    }

    clsDate dateFromNumberOfDays(short nDays, short year) {
        clsDate d;

        d.day = nDays;
        d.month = 1;
        d.year = year;
        short currentMonthDays = 0;
        while (true) {

            currentMonthDays = numberOfDaysInMonth(d.month, year);
            if (d.day <= currentMonthDays)
                break;
            d.day -= currentMonthDays;
            d.month++;
        }

        return d;
    }

    static short dayOfWeekOrder(short day, short month, short year) {
        int a = (14 - month) / 12;
        int y = year - a;
        int m = month + 12 * a - 2;

        return short((day + y + y / 4 + y / 400 - y / 100 + (31 * m) / 12) % 7);
    }

    static short dayOfWeekOrder(clsDate date) {
        return dayOfWeekOrder(date.day, date.month, date.year);
    }

    short dayOfWeekOrder() { return dayOfWeekOrder(*this); }

    static string getMonthName(short month) {
        string months[] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun",
                           "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
        return months[month - 1];
    }

    static string getMonthName(clsDate date) { return getMonthName(date.month); }

    string getMonthName() { return getMonthName(*this); }

    static void PrintMonthCalendar(short Month, short Year) {
        int NumberOfDays;
        // Index of the day from 0 to 6
        int current = dayOfWeekOrder(1, Month, Year);
        NumberOfDays = numberOfDaysInMonth(Month, Year);
        // Print the current month name
        printf("\n _______________%s_______________\n\n",
            getMonthName(Month).c_str());
        // Print the columns
        printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");
        // Print appropriate spaces
        int i;
        for (i = 0; i < current; i++)
            printf("     ");
        for (int j = 1; j <= NumberOfDays; j++) {
            printf("%5d", j);
            if (++i == 7) {
                i = 0;
                printf("\n");
            }
        }
        printf("\n _________________________________\n");
    }

    static void PrintMonthCalendar(clsDate date) {
        PrintMonthCalendar(date.month, date.year);
    }

    void PrintMonthCalendar() { PrintMonthCalendar(*this); }

    static void printYearCalendar(short year) {

        cout << " " << numChar('-', 35) << endl;
        cout << numChar(' ', 10) << "Calendar : " << year << endl;
        cout << " " << numChar('-', 35) << endl;

        for (int i = 1; i <= 12; i++) {
            PrintMonthCalendar(i, year);
        }
    }

    static void printYearCalendar(clsDate date) { printYearCalendar(date.year); }

    void printYearCalendar() { printYearCalendar(*this); }

    static bool isD1lessThanD2(clsDate d1, clsDate d2) {
        return (d1.year < d2.year) ? true
            : (d1.year > d2.year) ? false
            : (d1.month < d2.month) ? true
            : (d1.month > d2.month) ? false
            : (d1.day < d2.day) ? true
            : false;
    }

    bool islessThanD(clsDate D) { return isD1lessThanD2(*this, D); }

    static bool isDatesEqual(clsDate d1, clsDate d2) {
        return (d1.year == d2.year)
            ? ((d1.month == d2.month) ? ((d1.day == d2.day) ? true : false)
                : false)
            : false;
    }

    bool isLastDayInMonth(clsDate date) {
        return date.day == numberOfDaysInMonth(date.month, date.year);
    }

    bool isEqualWith(clsDate D) { return isDatesEqual(*this, D); }

    static bool isValidDate(clsDate date) {
        return (date.year >= 0) &&
            (numberOfDaysInMonth(date.month, date.year) >= date.day &&
                date.day > 0) &&
            (date.month <= 12 && date.month > 0);
    }

    bool isValid() { return isValidDate(*this); }

    static string getSystemDateTime() {
        int Year, Month, Day, hour, minutes, seconds;
        time_t t = time(0);
        tm* sTime = gmtime(&t);
        Year = sTime->tm_year + 1900;
        Month = sTime->tm_mon + 1;
        Day = sTime->tm_mday;
        hour = sTime->tm_hour;
        minutes = sTime->tm_min;
        seconds = sTime->tm_sec;
        return to_string(Day) + "/" + to_string(Month) + "/" + to_string(Year) + " - " + to_string(hour) + ":" + to_string(seconds) + ":" + to_string(seconds);
    }
};
