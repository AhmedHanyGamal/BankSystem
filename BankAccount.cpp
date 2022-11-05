#include <iostream>
#include "BankAccount.h"

using namespace std;

BankAccount::BankAccount() {
    balance = 0;
}
BankAccount::BankAccount(double initialBalance) {
    balance = initialBalance;
}
void BankAccount::accountIDSetter(const string& givenID){
    accountID = givenID;
}
string BankAccount::accountIDGetter(){
    return accountID;
}
void BankAccount::balanceSetter(double givenBalance){
    balance = givenBalance;
}
double BankAccount::balanceGetter(){
    return balance;
}
void BankAccount::withdraw(double withdrawalAmount) {
    if(balance - withdrawalAmount >= 0){
        balance -= withdrawalAmount;
        cout << "transaction complete\ncurrent balance : " << balance << endl;
    }
    else{
        cout << "not enough money in your balance to withdraw\n";
    }

}
void BankAccount::deposit(double depositAmount) {
    balance += depositAmount;
    cout << "transaction complete\ncurrent balance : " << balance << endl;
}