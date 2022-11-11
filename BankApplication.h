#ifndef BankApplication_h
#define BankApplication_h

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <unordered_map>
#include "Client.h"
#include "BankAccount.h"
#include "SavingsBankAccount.h"
#include "LabelGenerator.h"

class BankApplication {
private:
	std::vector<std::unique_ptr<Client>> clients;
	std::vector<std::unique_ptr<BankAccount>> accounts;
	std::unordered_map<std::string, size_t> clientAccountIndex;
	LabelGenerator idGenerator;

private:
	bool isValidName(const std::string& name);
	bool isValidPhoneNumber(const std::string& phoneNumber);
	bool login(std::string& accountID);

public:
	BankApplication() {}
	void displayMainMenu();
	bool createAccount();
	void listClientsAccounts();
	void withdrawMoney();
	void depositMoney();
	

};

#endif