#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class clsString {
private:
    string _myString;

    static char invertChar(char c) {
        if (c >= 'a' && c <= 'z')
            c = toupper(c);
        else
            c = tolower(c);
        return c;
    }

    static bool isVowel(char c) {
        c = toupper(c);
        return c == 'E' || c == 'A' || c == 'U' || c == 'I' || c == 'O';
    }

public:
    enum eCountingType {
        capital_letters = 0,
        small_letters = 1,
        all_letters = 2
    };

    clsString() { _myString = ""; }

    clsString(string s) { _myString = s; }

    string getString() { return _myString; }

    void setString(string s) { _myString = s; }

    //	__declspec(property(put = setString, get = getString)) string value;

    static string getFirstCharFromEachWord(string s) {
        string fS = "";
        bool inWord = 0;

        for (short i = 0; i < s.length(); i++) {
            if (s[i] != ' ' && !inWord) {
                fS += s[i];
            }
            inWord = s[i] == ' ' ? 0 : 1;
        }
        return fS;
    }

    string getFirstCharFromEachWord() {
        return getFirstCharFromEachWord(_myString);
    }

    static void upperFirstCharFromEachWord(string& s) {
        bool inWord = 0;
        for (short i = 0; i < s.length(); i++) {
            if (s[i] != ' ' && !inWord) {
                s[i] = toupper(s[i]);
            }
            inWord = s[i] == ' ' ? 0 : 1;
        }
    }

    void upperFirstCharFromEachWord() { upperFirstCharFromEachWord(_myString); }

    static string upperString(string s) {

        for (int i = 0; i < s.length(); i++) {
            s[i] = toupper(s[i]);
        }
        return s;
    }

    string upperString() { return upperString(_myString); }

    static string lowerString(string s) {

        for (int i = 0; i < s.length(); i++) {
            s[i] = tolower(s[i]);
        }
        return s;
    }

    string lowerString() { return lowerString(_myString); }

    static string invertStringCases(string s) {
        for (int i = 0; i < s.length(); i++) {
            invertChar(s[i]);
        }
        return s;
    }

    string invertStringCases() { return invertStringCases(_myString); }

    static short countLetters(string s, eCountingType cntType = all_letters) {
        short cnt = 0;
        switch (cntType) {
        case eCountingType::all_letters: {
            for (short i = 0; i < s.length(); i++) {
                if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
                    cnt++;
            }
            break;
        }
        case eCountingType::capital_letters: {
            for (short i = 0; i < s.length(); i++) {
                if (s[i] >= 'A' && s[i] <= 'Z')
                    cnt++;
            }
            break;
        }
        case eCountingType::small_letters: {
            for (short i = 0; i < s.length(); i++) {
                if (s[i] >= 'a' && s[i] <= 'z')
                    cnt++;
            }
            break;
        }
        }
        return cnt;
    }

    short countLetters(eCountingType cntType = all_letters) {
        return countLetters(_myString, cntType);
    }

    static short getCharOccurency(string s, char o, bool sensitivity = 1) {
        short cnt = 0;
        if (sensitivity) {
            for (short i = 0; i < s.length(); i++) {
                if (s[i] == o) {
                    cnt++;
                }
            }
        }
        else {
            for (short i = 0; i < s.length(); i++) {
                if (toupper(s[i]) == toupper(o)) {
                    cnt++;
                }
            }
        }
        return cnt;
    }

    short getCharOccurency(char o, bool sensitivity = 1) {
        return getCharOccurency(_myString, o, sensitivity);
    }

    static short countVowels(string s) {
        short cnt = 0;
        for (short i = 0; i < s.length(); i++) {
            if (isVowel(s[i]))
                cnt++;
        }
        return cnt;
    }

    short countVowels() { return countVowels(_myString); }

    static vector<string> splitString(string s, string spt) {
        vector<string> vString;
        short ipos = 0;
        short spos = 0;
        while ((spos = s.find(spt, ipos)) != string::npos) {
            vString.push_back(s.substr(ipos, spos - ipos));
            ipos = spos + spt.length();
        }
        vString.push_back(s.substr(ipos));
        return vString;
    }
};
