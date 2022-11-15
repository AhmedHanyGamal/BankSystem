// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include <iostream>
#include <string>
#include "Client.h"

Client::Client(std::string fullName, std::string fullAddress, std::string phone) :
	fullName(std::move(fullName)),
	fullAddress(std::move(fullAddress)),
	phoneNumber(std::move(phone))
{}

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
	this->fullName = std::move(fullName);
}

void Client::setAddress(std::string fullAddress)
{
	this->fullAddress = std::move(fullAddress);
}

void Client::setPhoneNumber(std::string phone)
{
	this->phoneNumber = std::move(phone);
}