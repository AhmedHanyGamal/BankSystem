// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include <iostream>
#include "BankAccount.h"

using namespace std;

BankAccount::BankAccount() {
    balance = 0;
    accountType = 'b';
}

BankAccount::BankAccount(double initialBalance) {
    balance = initialBalance;
    accountType = 'b';
}

void BankAccount::setAccountID(const string& givenID){
    accountID = givenID;
}

string BankAccount::getAccountID(){
    return accountID;
}

bool BankAccount::setBalance(double givenBalance){
    balance = givenBalance;
    return true;
}

double BankAccount::getBalance() 
{
    return balance;
}

char BankAccount::getAccountType() const
{
    return accountType;
}

bool BankAccount::withdraw(double withdrawalAmount) {
    if(balance - withdrawalAmount >= 0){
        balance -= withdrawalAmount;
        return true;
    }
    else {
        return false;
    }

}

bool BankAccount::deposit(double depositAmount) {
    balance += depositAmount;
    return true;
}

void BankAccount::displayType() const
{
    std::cout << "Account Type: Basic Bank Account" << std::endl;
}