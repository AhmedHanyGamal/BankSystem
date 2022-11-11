#ifndef SavingsBankAccount_h
#define SavingsBankAccount_h

#include <iostream>
#include "BankAccount.h"

class SavingsBankAccount : public BankAccount {
private:
    const int minimumBalance = 1000;

public:
    SavingsBankAccount(double);
    bool setBalance(double);
    bool withdraw(double); // returns true if transaction is accepted
    bool deposit(double); // returns true if transaction is accepted

};





#endif