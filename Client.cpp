#include <iostream>
#include <string>
#include "Client.h"

Client::Client(std::string fullName, std::string fullAddress, std::string phone)
{
	this->fullName = fullName;
	this->fullAddress = fullAddress;
	this->phoneNumber = phone;
}

std::string Client::getName() const
{
	return fullName;
}

std::string Client::getAddress() const
{
	return fullAddress;
}

std::string Client::getPhoneNumber() const
{
	return phoneNumber;
}

void Client::setName(std::string fullName)
{
	this->fullName = fullName;
}

void Client::setAddress(std::string fullAddress)
{
	this->fullAddress = fullAddress;
}

void Client::setPhoneNumber(std::string phone)
{
	this->phoneNumber = phone;
}

void Client::setClientAccount(BankAccount&& account)
{
	this->clientAccount = std::make_unique<BankAccount>(BankAccount(std::move(account)));
}