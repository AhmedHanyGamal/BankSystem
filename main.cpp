#include <iostream>
#include "BankApplication.h"

using namespace std;

int main()
{
	BankApplication app;

	while (true)
	{
		system("cls");
		app.displayMainMenu();
		cout << "Please Enter Choice =========> ";

		int choice;
		cin >> choice;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(100,'\n');
			
			cout << "plz enter a valid number: ";
			cin >> choice;
		}
		if (choice == 1)
		{
			if (!app.createAccount())
				cout << "Please Follow The Rules of Signing up" << endl;
			system("pause");
			continue;
		}
		if (choice == 2)
		{
			app.listClientsAccounts();
			system("pause");
			continue;
		}
		if (choice == 3)
		{
			app.withdrawMoney();
			system("pause");
			continue;
		}
		if (choice == 4)
		{
			app.depositMoney();
			system("pause");
			continue;
		}
		if (choice == 5)
		{
			break;
		}
	}

	return 0;
}

// do the ID stuff