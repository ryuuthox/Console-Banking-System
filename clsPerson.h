#pragma once

#include <iostream>

using namespace std;

class clsPerson {
private:
    string _firstName;
    string _lastName;
    string _phone;
    string _email;

public:
    clsPerson(string firstName, string lastName, string phone, string email) {
        _firstName = firstName;
        _lastName = lastName;
        _phone = phone;
        _email = email;
    }

    string getFullName() { return _firstName + ' ' + _lastName; }
    void setFirstName(string firstName) { _firstName = firstName; }

    string getFirstName() { return _firstName; }

    void setLastName(string lastName) { _lastName = lastName; }

    string getLastName() { return _lastName; }

    void setPhoneNumber(string phone) { _phone = phone; }

    string getPhoneNumber() { return _phone; }

    void setEmail(string email) { _email = email; }

    string getEmail() { return _email; }
};
