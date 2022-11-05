#include <iostream>
#include "SavingsBankAccount.h"

using namespace std;

SavingsBankAccount::SavingsBankAccount(double initialBalance) {
    if(initialBalance >= minimumBalance){
        balance = initialBalance;
        cout << "transaction complete\nyour current balance is " << balance << endl;
    }
    else{
        cout << "initial balance not big enough, must be at least  1000\n";
    }
}

void SavingsBankAccount::balanceSetter(double givenBalance){
    if(givenBalance >= minimumBalance){
        balance = givenBalance;
        cout << "transaction complete\nyour current balance is " << balance << endl;
    }
    else{
        cout << "balance not big enough, must be at least  1000\n";
    }
}
void SavingsBankAccount::withdraw(double withdrawalAmount) {
    if(balance - withdrawalAmount >= minimumBalance){
        balance -= withdrawalAmount;
        cout << "transaction complete\ncurrent balance : " << balance << endl;
    }
    else{
        cout << "not enough money in your balance to withdraw\n(keep in mind that there is a minimum balance of 1000 dollars)\n";
    }
}

void SavingsBankAccount::deposit(double depositAmount) {
    if(depositAmount >= 100){
        balance += depositAmount;
        cout << "transaction complete\ncurrent balance : " << balance << endl;
    }
    else{
        cout << "not enough money to deposit\n(you can only deposit 100 dollars or more, since you opened a savings account)\n";
    }
}