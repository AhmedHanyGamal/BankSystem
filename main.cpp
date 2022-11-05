#include <iostream>
#include "SavingsBankAccount.h"
#include "BankAccount.h"

using namespace std;





int main() {
    BankAccount bob(1000);
    cout << bob.balanceGetter() << endl;
    bob.balanceSetter(2000);
    cout << bob.balanceGetter() << endl;




    return 0;
}


//do the ID stuff