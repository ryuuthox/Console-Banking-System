#pragma once
#include "clsDate.h"
#include <ios>
#include <iostream>
#include <limits>
#include <locale>
#include <string>
#include <vector>

using namespace std;
class clsInputOutput {
public:
    static int readIntNumber(string WarningMessage) {
        int r = 0;

        while (!(cin >> r)) {
            cout << WarningMessage << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return r;
    }

    static float readFloatNumber(string WarningMessage) {
       float r = 0;

        while (!(cin >> r)) {
            cout << WarningMessage << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return r;
    }

    static short readShortNumber(string WarningMessage) {
        short r = 0;

        while (!(cin >> r)) {
            cout << WarningMessage << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return r;
    }

    static char readChar(string WarningMessage) {
        char c;
        while (!(cin >> c)) {
            cout << WarningMessage << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return c;
    }

    static int readIntNumberBetween(int from, int to, string warningMessage) {
        int i = 0;
        while (!(cin >> i) || i < from || i > to) {
            cout << warningMessage << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return i;
    }

    static short readShortNumberBetween(short from, short to, string warningMessage) {
        short i = 0;
        while (!(cin >> i) || i < from || i > to) {
            cout << warningMessage << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return i;
    }


    static double readDblNumber(string warningMessage) {
        double r = 0;

        while (!(cin >> r)) {
            cout << warningMessage << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return r;
    }

    static string readString(string warningMessage) {
        string s = "";

        while (!(getline(cin >> ws, s))) {
            cout << warningMessage << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        /*cin.ignore(numeric_limits<streamsize>::max(), '\n');*/
        return s;
    }

    static double readDblNumberBetween(int from, int to, string warningMessage) {
        double i = 0;
        while (!(cin >> i) || i < from || i > to) {
            cout << warningMessage << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return i;
    }

    static bool isNumberBetween(int number, int from, int to) {
        return (number >= from && number <= to);
    }

    static bool isNumberBetween(short number, short from, short to) {
        return (number >= from && number <= to);
    }

    static bool isNumberBetween(double number, double from, double to) {
        return (number >= from && number <= to);
    }

    static bool isNumberBetween(float number, float from, float to) {
        return (number >= from && number <= to);
    }

    static bool isDateBetween(clsDate date0, clsDate date1, clsDate date2) {
        return (date0.islessThanD(date2) && date1.islessThanD(date0)) ||
            date0.isEqualWith(date1) || date0.isEqualWith(date2);
    }

    static bool isValidDate(clsDate date) { return date.isValid(); }
};
