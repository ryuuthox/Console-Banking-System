#pragma once
#include "clsInputOutput.h"
#include "clsPerson.h"
#include "clsString.h"
#include "clsUtil.h"
#include <cstdio>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class clsBankClient : public clsPerson {
private:
   
    enum eClientMode { empty_mode = 0, update_mode = 1, add_New_mode = 2 };
    string _accountNumber;
    string _pinCode;
    double _accountBallance;
    eClientMode _mode;

    static string _convertClientObjectIntoLine(clsBankClient& client,string spt = "#//#") {
        string line = "";
        line += (client.getFirstName() + spt);
        line += (client.getLastName() + spt);
        line += (client.getEmail() + spt);
        line += (client.getPhoneNumber() + spt);
        line += (client.getAccountNumber() + spt);
        line += (client.getPinCode() + spt);
        line += to_string(client.getAccountBallance());
        return line;
    }

    static clsBankClient _convertLineIntoClientObject(string line,string spt = "#//#") {

        vector<string> vClient = clsString::splitString(line, spt);
        return clsBankClient(vClient[0], vClient[1], vClient[2], vClient[3],
            vClient[4], vClient[5], stod(vClient[6]),
            eClientMode::update_mode);
    }

    static clsBankClient _getEmptyClientObject() {
        return clsBankClient("", "", "", "", "", "", 0, eClientMode::empty_mode);
    }

    static void _loadClientsVectorOnFile(vector<clsBankClient>& vClients) {
        fstream myFile;
        myFile.open("Clients.txt", ios::out);
        if (myFile.is_open()) {
            for (clsBankClient& cl : vClients) {
                if (!cl.isEmpty())
                    myFile << _convertClientObjectIntoLine(cl) << endl;
            }
        }
        myFile.close();
    }

   static vector<clsBankClient> _loadClientsFileOnVector() {
        vector<clsBankClient> vClients;
        fstream myFile;
        myFile.open("Clients.txt", ios::in);
        if (myFile.is_open()) {
            string line;
            while (getline(myFile, line)) {
                vClients.push_back(_convertLineIntoClientObject(line));
            }
        }
        myFile.close();
        return vClients;
    }

    void _update() {
        vector<clsBankClient> vClients = _loadClientsFileOnVector();
        for (clsBankClient& client : vClients) {
            if (client._accountNumber == this->_accountNumber) {
                client = *this;
            }
        }
        _loadClientsVectorOnFile(vClients);
    }

    void _addNewLineToClientFile(string line) {
        fstream myFile;
        myFile.open("Clients.txt", ios::out | ios::app);
        if (myFile.is_open()) {
            myFile << line << endl;
            myFile.close();
        }
        
    }

    void _addNewClient(clsBankClient& client) {
        _addNewLineToClientFile(_convertClientObjectIntoLine(client));
    }

    string _prepareLogTransferRecord(double amount, clsBankClient& destClient,string spt="#||#") {
            return clsDate::getSystemDateTime() + spt + this->getAccountNumber() + spt + destClient.getAccountNumber() + spt +to_string(amount)+spt+ to_string(this->getAccountBallance())+spt+to_string(destClient.getAccountBallance())+spt+currentUser.getUserName();
    }

    void _addLogTrsToFile(string line) {
        fstream myFile;
        myFile.open("logsTransfer.txt", ios::out | ios::app);
        if (myFile.is_open()) {
            myFile << line << endl;
        }
        myFile.close();
    }

    void _saveLogTransfer(double amount, clsBankClient& destClient) {
        _addLogTrsToFile(_prepareLogTransferRecord(amount, destClient));
    }

    struct stTrnsferLogRecord;

    static stTrnsferLogRecord _ConvertTransferLogLineToRecord(string Line, string Seperator = "#||#")
    {
        stTrnsferLogRecord TrnsferLogRecord;

        vector <string> vTrnsferLogRecordLine = clsString::splitString(Line, Seperator);
        TrnsferLogRecord.DateTime = vTrnsferLogRecordLine[0];
        TrnsferLogRecord.SourceAccountNumber = vTrnsferLogRecordLine[1];
        TrnsferLogRecord.DestinationAccountNumber = vTrnsferLogRecordLine[2];
        TrnsferLogRecord.Amount = stod(vTrnsferLogRecordLine[3]);
        TrnsferLogRecord.srcBalanceAfter = stod(vTrnsferLogRecordLine[4]);
        TrnsferLogRecord.destBalanceAfter = stod(vTrnsferLogRecordLine[5]);
        TrnsferLogRecord.UserName = vTrnsferLogRecordLine[6];

        return TrnsferLogRecord;

    }
    
public:
    enum enSave { saveFailed_Empty = 0, saveSucceded = 1, saveFailed_Exist = 2 };
    struct stTrnsferLogRecord
    {
        string DateTime;
        string SourceAccountNumber;
        string DestinationAccountNumber;
        double Amount;
        double srcBalanceAfter;
        double destBalanceAfter;
        string UserName;

    };
    clsBankClient(string firstName, string lastName, string email, string phone,string accountNumber, string codePin, double accountBallance,eClientMode mode)
        : clsPerson(firstName, lastName, phone, email) {
        _accountBallance = accountBallance;
        _accountNumber = accountNumber;
        _pinCode = codePin;
        _mode = mode;
    }

    string getAccountNumber() { return _accountNumber; }

    void setPinCode(string pinCode) { _pinCode = pinCode; }

    string getPinCode() { return _pinCode; }

    void setAccountBallance(double accountBallance) {
        _accountBallance = accountBallance;
    }

    double getAccountBallance() { return _accountBallance; }

    static clsBankClient findClient(string accountNumber) {
        fstream myFile;

        myFile.open("Clients.txt", ios::in);
        if (myFile.is_open()) {
            string line;
            while (getline(myFile, line)) {
                clsBankClient Client = _convertLineIntoClientObject(line);
                if (Client._accountNumber == accountNumber) {
                    myFile.close();
                    return Client;
                }
            }
        }
        myFile.close();
        return _getEmptyClientObject();
    }

    static clsBankClient findClient(string accountNumber, string codePine) {
        fstream myFile;

        myFile.open("Clients.txt", ios::in);
        if (myFile.is_open()) {
            string line;
            while (getline(myFile, line)) {
                clsBankClient Client = _convertLineIntoClientObject(line);
                if (Client._accountNumber == accountNumber &&
                    Client._pinCode == codePine) {
                    myFile.close();
                    return Client;
                }
            }
        }
        myFile.close();
        return _getEmptyClientObject();
    }

    static bool isEmpty(clsBankClient& client) {
        return client._mode == empty_mode;
    }
    bool isEmpty() { return isEmpty(*this); }

    static bool isClientExist(string accountNumber) {
        clsBankClient Client = findClient(accountNumber);
        return !Client.isEmpty();
    }

    static clsBankClient getAddNewClientObject(string AN) {
        return clsBankClient("", "", "", "", AN, "", 0, eClientMode::add_New_mode);
    }

    void Delete() {
        vector<clsBankClient> vClients = _loadClientsFileOnVector();
        for (clsBankClient& client : vClients) {
            if (client.getAccountNumber() == _accountNumber) {
                client = _getEmptyClientObject();
            }
        }
        _loadClientsVectorOnFile(vClients);
        *this = _getEmptyClientObject();
    }
  
    static vector<clsBankClient> getAllClientsInVector() {
        return _loadClientsFileOnVector();
    }

    enSave save() {
        switch (_mode) {
        case eClientMode::empty_mode:
            return enSave::saveFailed_Empty;
        case eClientMode::update_mode:
           this->_update();
           return enSave::saveSucceded;
        case eClientMode::add_New_mode:
            if (isClientExist(_accountNumber)) {
                return enSave::saveFailed_Exist;
            }
            _addNewClient(*this);
            return enSave::saveSucceded;
        }
   }

   static double getTotalBallances() {
        vector<clsBankClient> vClients = _loadClientsFileOnVector();
        double tot = 0;
        for (clsBankClient& client : vClients) {
            tot += client._accountBallance;
        }
        return tot;
  }

    void deposit(double amount) {
        _accountBallance += amount;
        save();
   }

    bool withDraw(double amount) {
        if (!_accountBallance < amount) {
            _accountBallance -= amount;
            save();
            return 1;
        }
        else {
            return 0;
        }
    }

    bool transfer(double amount, clsBankClient& destClient) {
        if (amount > _accountBallance) {
            return 0;
        }
        else {
            this->withDraw(amount);
            destClient.deposit(amount);
            _saveLogTransfer(amount, destClient);
            return 1;
        }
    }


    static  vector <stTrnsferLogRecord> GetTransfersLogList()
    {
        vector <stTrnsferLogRecord> vTransferLogRecord;

        fstream MyFile;
        MyFile.open("logsTransfer.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {

            string Line;

            stTrnsferLogRecord TransferRecord;

            while (getline(MyFile, Line))
            {

                TransferRecord = _ConvertTransferLogLineToRecord(Line);

                vTransferLogRecord.push_back(TransferRecord);

            }

            MyFile.close();

        }

        return vTransferLogRecord;

    }
   
};
