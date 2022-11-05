#pragma once

#include <iostream>
using namespace std;


class BankAccount{
protected:
    string accountID;
    double balance;


public:
    BankAccount();
    BankAccount(double );
    void accountIDSetter(const string& );
    string accountIDGetter();
    virtual void balanceSetter(double );
    double balanceGetter();
    virtual void withdraw(double );
    virtual void deposit(double );

};
