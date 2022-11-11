#include <iostream>
#include <stdexcept>
#include "SavingsBankAccount.h"

using namespace std;

SavingsBankAccount::SavingsBankAccount(double initialBalance) {
    if(initialBalance >= minimumBalance){
        balance = initialBalance;
        accountType = 's';
    }
    else {
        throw std::invalid_argument("initial balance not big enough, must be at least 1000\n");
    }
}

bool SavingsBankAccount::setBalance(double givenBalance){
    if(givenBalance >= minimumBalance){
        balance = givenBalance;
        return true;
    }
    else{
        return false;
    }
}
bool SavingsBankAccount::withdraw(double withdrawalAmount) {
    if(balance - withdrawalAmount >= minimumBalance){
        balance -= withdrawalAmount;
        return true;
    }
    else{
        return false;
    }
}

bool SavingsBankAccount::deposit(double depositAmount) {
    if(depositAmount >= 100){
        balance += depositAmount;
        return true;
    //    cout << "transaction complete\ncurrent balance : " << balance << endl;
    }
    else{
        return false;
    }
}