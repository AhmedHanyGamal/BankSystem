#include <iostream>
#include <regex>
#include <string>
#include <memory>
#include "BankApplication.h"

bool BankApplication::isValidName(const std::string& name)
{
	for (int i = 0; i < name.size(); i++)
	{
		if (isdigit(name[i]))
			return false;
	}

	return true;
}

bool BankApplication::isValidPhoneNumber(const std::string& phoneNumber)
{
	return regex_match(phoneNumber, std::regex("^(01)[0125][0-9]{8}"));
}

void BankApplication::displayMainMenu()
{
	std::cout << "Welcome to FCAI Banking Application!" << std::endl;
	std::cout << "1. Create a New Account" << std::endl;
	std::cout << "2. List Clients and Accounts" << std::endl;
	std::cout << "3. Withdraw Money" << std::endl;
	std::cout << "4. Deposit Money" << std::endl;
	std::cout << "5. Exit Program\n" << std::endl;
}

bool BankApplication::createAccount()
{
	std::string name;
	std::cout << "Please Enter Client Name =========> ";
	std::cin >> name;
	if (!isValidName(name))
		return false;

	std::string address;
	std::cout << "\nPlease Enter Client Address =======> ";
	std::cin >> address;
	
	std::string phoneNumber;
	std::cout << "\nPlease Enter Client Phone =======> ";
	std::cin >> phoneNumber;
	if (!isValidPhoneNumber(phoneNumber))
		return false;

	int accountTypeChoice;
	std::cout << "\nWhat Type of Account Do You Like? (1) Basic (2) Saving, Type 1 or 2 =========> ";
	std::cin >> accountTypeChoice;
	if (accountTypeChoice != 1 && accountTypeChoice != 2)
		return false;

	char accountTypeChar;
	if (accountTypeChoice == 1)
		accountTypeChar = 'b';
	if (accountTypeChoice == 2)
		accountTypeChar = 's';
	
	std::unique_ptr<Client> newClient(new Client(name, address, phoneNumber));
	clients.push_back(std::move(newClient));
	
	double startingBalance;
	std::cout << "\nPlease Enter the Starting Balance =========> ";
	std::cin >> startingBalance;
	while (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(100,'\n');
			
			std::cout << "plz enter a valid starting amount of balance : ";
			std::cin >> startingBalance;
		}

	idGenerator.setLabel("FCAI-");
	idGenerator.setLabelNumber(clients.size() - 1); // gets last id number

	if (accountTypeChoice == 1)
	{
		std::unique_ptr<BankAccount> newAccount(new BankAccount(startingBalance));
		newAccount->setAccountID(idGenerator.nextLabel());
		
		newAccount->setClientInfo(Client(name, address, phoneNumber));
		BankAccount temp(startingBalance);
		temp.setAccountID(idGenerator.getLabelStr());
		clients[clients.size() - 1]->setClientAccount(std::move(temp));

		accounts.push_back(std::move(newAccount));
		clientAccountIndex.insert({idGenerator.getLabelStr(), clients.size() - 1});
		

		std::cout << "\nAn account was created with ID: " << idGenerator.getLabelStr();
		std::cout << "\nStarting Balance: " << startingBalance << " L.E." << std::endl;

		return true;
	}
	if (accountTypeChoice == 2)
	{
		try
		{
			std::unique_ptr<BankAccount> newAccount(new SavingsBankAccount(startingBalance));
			newAccount->setAccountID(idGenerator.nextLabel());
			accounts.push_back(std::move(newAccount));
			clientAccountIndex.insert({ idGenerator.getLabelStr(), clients.size() - 1 });

			std::cout << "\nAn account was created with ID: " << idGenerator.getLabelStr();
			std::cout << "\nStarting Balance: " << startingBalance << " L.E." << std::endl;

			return true;
		}
		catch (const std::invalid_argument& notEnoughBalance)
		{
			std::cout << notEnoughBalance.what() << std::endl;
			clients.pop_back();

			return false;
		}
	}
	return false;
}


void BankApplication::listClientsAccounts()
{
	//system("cls");
	std::cout << "------------------------------------" << std::endl;
	for (int i = 0; i < clients.size(); i++)
	{
		std::cout << "Name: " << clients[i]->getName() << std::endl;
		std::cout << "Address: " << clients[i]->getAddress() << std::endl;
		std::cout << "PhoneNumber: " << clients[i]->getPhoneNumber() << std::endl;
		std::cout << "Account ID: " << accounts[i]->getAccountID() << std::endl;
		std::cout << "Balance: " << accounts[i]->getBalance() << std::endl;
		std::cout << "------------------------------------" << std::endl;
	}
}

bool BankApplication::login(std::string& accountID)
{
	while (!clientAccountIndex.count(accountID))
	{
		int choice;
		std::cout << "Please Enter A Correct ID, This ID Does Not Exist.\n";
		std::cout << "1 - Try Again.\n2 - Return To Main Menu\n";
		std::cout << "Type 1 or 2\nPlease enter your choice =========> ";
		std::cin.clear();
		std::cin.ignore(100,'\n');
		std::cin >> choice;
		while (std::cin.fail() || (choice != 1 && choice != 2))
		{
			std::cin.clear();
			std::cin.ignore(100,'\n');
			
			std::cout << "plz enter a valid number or choice =========> ";
			std::cin >> choice;
		}

		if (choice == 2)
		{
			return false;
		}
		if (choice == 1)
		{
			std::cout << "\nPlease Enter Account ID (e.g., FCAI-015) =========> ";
			std::cin >> accountID;
		}
	}

	size_t index = clientAccountIndex[accountID];
	std::cout << "Account ID: " << accounts[index]->getAccountID() << std::endl;
	std::cout << "Account Type: " << accounts[index]->getAccountType() << std::endl;
	std::cout << "Balance: " << accounts[index]->getBalance() << std::endl;

	return true;
}

void BankApplication::withdrawMoney()
{
	std::string accountID;
	std::cout << "Please Enter Account ID (e.g., FCAI-015) =========> ";
	std::cin >> accountID;
	if (!this->login(accountID))
		return;
	size_t index = clientAccountIndex[accountID];
	
	double amount;
	std::cout << "Please Enter The Amount to Withdraw =========> ";
	std::cin >> amount;
	while (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(100,'\n');
		
		std::cout << "plz enter a valid amount : ";
		std::cin >> amount;
	}
	while (!accounts[index]->withdraw(amount))
	{
		if (accounts[index]->getAccountType() == 'b')
		{
			std::cout << "not enough money in your balance to withdraw\n";
		}
		if (accounts[index]->getAccountType() == 's')
		{
			std::cout << "not enough money in your balance to withdraw\n";
			std::cout << "(keep in mind that there is a minimum balance of 1000 dollars)\n";
		}

		std::cout << "1 - Try Again.\n2 - Return To Main Menu.\n";
		std::cout << "Type 1 or 2\nPlease enter your choice =========> ";

		int choice;
		std::cin >> choice;
		while (std::cin.fail() || (choice != 1 && choice != 2))
		{
			std::cin.clear();
			std::cin.ignore(100,'\n');
			
			std::cout << "plz enter a valid number or choice =========> ";
			std::cin >> choice;
		}

		if (choice == 2)
		{
			return;
		}
		if (choice == 1)
		{
			std::cout << "\nPlease Enter The Amount to Withdraw =========> ";
			std::cin >> amount;
		}
	}

	std::cout << "transaction complete\ncurrent balance : ";
	std::cout << accounts[index]->getBalance() << std::endl;


}

void BankApplication::depositMoney()
{
	std::string accountID;
	std::cout << "Please Enter Account ID (e.g., FCAI-015) =========> ";
	std::cin >> accountID;
	if (!this->login(accountID))
		return;
	size_t index = clientAccountIndex[accountID];

	double amount;
	std::cout << "Please Enter The Amount to Deposit =========> ";
	std::cin >> amount;
	while (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(100,'\n');
		
		std::cout << "plz enter a valid amount : ";
		std::cin >> amount;
	}

	while (!accounts[index]->deposit(amount))
	{
		if (accounts[index]->getAccountType() == 'b')
		{
			std::cout << "not enough money in your balance to deposit\n";
		}
		if (accounts[index]->getAccountType() == 's')
		{
			std::cout << "not enough money to deposit\n";
			std::cout << "(you can only deposit 100 dollars or more, since you opened a savings account)\n";
		}

		std::cout << "1 - Try Again.\n2 - Return To Main Menu.\n";
		std::cout << "Type 1 or 2\nPlease enter your choice =========> ";

		int choice;
		std::cin >> choice;
		while (std::cin.fail() || (choice != 1 && choice != 2))
		{
			std::cin.clear();
			std::cin.ignore(100,'\n');
			
			std::cout << "plz enter a valid number or choice =========> ";
			std::cin >> choice;
		}

		if (choice == 2)
		{
			return;
		}
		if (choice == 1)
		{
			std::cout << "\nPlease Enter The Amount to Withdraw =========> ";
			std::cin >> amount;
		}
	}

	std::cout << "transaction complete\ncurrent balance : ";
	std::cout << accounts[index]->getBalance() << std::endl;
}