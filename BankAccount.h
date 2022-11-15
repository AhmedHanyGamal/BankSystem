#pragma once

#include <iostream>
#include <string>
#include <memory>

class Client;

#include "Client.h"

class BankAccount {
protected:
    std::string accountID;
    double balance;
    char accountType; // 'b' if basic account, 's' if saving account

public:
    Client* clientInfo;

public:
    BankAccount();
    BankAccount(double);

    std::string getAccountID();
    double getBalance();
    char getAccountType() const;

    virtual bool setBalance(double);
    void setAccountID(const std::string&);

    virtual bool withdraw(double); // returns true if transaction is accepted
    virtual bool deposit(double); // returns true if transaction is accepted

    virtual void displayType() const;
};
