#pragma once
#include "clsDate.h"
#include <cstdlib>
#include <ctime>
#include <ios>
#include <iostream>
#include <limits>
#include <random>

using namespace std;

class clsUtil {

public:
    enum eCharType {
        small_letters = 1,
        cappital_letters = 2,
        digits = 3,
        all_chars = 4,
    };

    static void seedRandom() { srand((unsigned)(int)time(0)); }

    static int getRandomNum(int from, int to) {
        return rand() % (to - from + 1) + from;
    }

    static void pauseScreen(string prompt) {
        cout << prompt << flush;
        system("bash -c 'read -n 1 -s -r'");
        cout << endl;
    }

    static char getRandChar(eCharType charType) {
        switch (charType) {
        case small_letters:
            return (char)getRandomNum('a', 'z');
        case cappital_letters:
            return (char)getRandomNum('A', 'Z');
        case digits:
            return (char)getRandomNum('0', '9');
        case all_chars:
            return (char)getRandChar((eCharType)getRandomNum(1, 3));
        default:
            return ' ';
        }
    }

    static string generateRandomWord(eCharType charType, short nChar) {
        string w = "";
        for (short i = 0; i < nChar; i++) {
            w += getRandChar(charType);
        }
        return w;
    }

    static string generateKey(eCharType charType) {
        string k = "";
        for (short i = 0; i < 3; i++) {
            k += (generateRandomWord(charType, 4) + '-');
        }
        k += generateRandomWord(charType, 4);
        return k;
    }

    static void generateKeys(eCharType charType, short nKeys) {
        for (short i = 0; i < nKeys; i++) {
            cout << generateKey(charType) << endl;
        }
    }

    static void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }

    static void swap(string& s1, string& s2) {
        string stemp = s1;
        s1 = s2;
        s2 = stemp;
    }

    static void swap(clsDate& d1, clsDate& d2) {
        clsDate dtemp = d1;
        d1 = d2;
        d2 = dtemp;
    }

    static void shuffleArray(int arr[], short dim) {
        for (short i = 0; i < dim; i++) {
            swap(arr[getRandomNum(0, dim - 1)], arr[getRandomNum(0, dim - 1)]);
        }
    }

    static void shuffleArray(string arr[], short dim) {
        for (short i = 0; i < dim; i++) {
            swap(arr[getRandomNum(0, dim - 1)], arr[getRandomNum(0, dim - 1)]);
        }
    }

    static void fillArrayWithRandomNums(int arr[], int dim, int from, int to) {
        for (int i = 0; i < dim; i++) {
            arr[i] = getRandomNum(from, to);
        }
    }

    static void fillArrayWithRandomWords(string arr[], int dim,
        eCharType charType, short nChar) {
        for (int i = 0; i < dim; i++) {
            arr[i] = generateRandomWord(charType, nChar);
        }
    }
    static string getRepeatedChar(char c, short nChar) {
        string s = "";
        for (short i = 0; i < nChar; i++) {
            s += c;
        }
        return s;
    }

    static char encryptChar(char c, char key) { return c ^ key; }
    static char decryptChar(char c, char key) { return c ^ key; }

    static string encryptText(string s, char key='$') {
        string text = "";
        for (int i = 0; i < s.length(); i++) {
            text+=encryptChar(s[i], key);
        }
        return text;
    }

    static string decryptText(string s, char key='$') {
        string text = "";
        for (int i = 0; i < s.length(); i++) {
            text+=decryptChar(s[i], key);
        }
        return text;
    }

    static string NumberToText(int Number)
    {

        if (Number == 0)
        {
            return "";
        }

        if (Number >= 1 && Number <= 19)
        {
            string arr[] = { "", "One","Two","Three","Four","Five","Six","Seven",
        "Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen",
          "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };

            return  arr[Number] + " ";

        }

        if (Number >= 20 && Number <= 99)
        {
            string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
            return  arr[Number / 10] + " " + NumberToText(Number % 10);
        }

        if (Number >= 100 && Number <= 199)
        {
            return  "One Hundred " + NumberToText(Number % 100);
        }

        if (Number >= 200 && Number <= 999)
        {
            return   NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100);
        }

        if (Number >= 1000 && Number <= 1999)
        {
            return  "One Thousand " + NumberToText(Number % 1000);
        }

        if (Number >= 2000 && Number <= 999999)
        {
            return   NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);
        }

        if (Number >= 1000000 && Number <= 1999999)
        {
            return  "One Million " + NumberToText(Number % 1000000);
        }

        if (Number >= 2000000 && Number <= 999999999)
        {
            return   NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000000);
        }

        if (Number >= 1000000000 && Number <= 1999999999)
        {
            return  "One Billion " + NumberToText(Number % 1000000000);
        }
        else
        {
            return   NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number % 1000000000);
        }


    }

};
