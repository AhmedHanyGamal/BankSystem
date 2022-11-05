#ifndef SavingsBankAccount_h

#define SavingsBankAccount_h
#include <iostream>
#include "BankAccount.h"

class SavingsBankAccount : public BankAccount{
private:
    const int minimumBalance = 1000;



public:
    SavingsBankAccount(double);
    void balanceSetter(double );
    void withdraw(double );
    void deposit(double );


};





#endif