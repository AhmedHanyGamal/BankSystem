#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include <memory>

class BankAccount;

#include "BankAccount.h"

class Client {
private:
	std::string fullName;
	std::string fullAddress;
	std::string phoneNumber;
	
public:
	BankAccount* clientAccount;

public:
	Client(std::string fullName, std::string fullAddress, std::string phone);

	std::string getName() const;
	std::string getAddress() const;
	std::string getPhoneNumber() const;

	void setName(std::string fullName);
	void setAddress(std::string fullAddress);
	void setPhoneNumber(std::string phone);

	void deletePtr();
};







#endif