 #include <iostream>

using namespace std;

double Total_bal = 1000.0;

void deposit() {
    double amount;

    cout << "Enter how much amount you want to deposit: ";
    cin >> amount;

    if (amount > 0) {
        Total_bal += amount;
        cout << "Deposited successfully. Your new balance is: " << Total_bal << endl;
    } else {
        cout << "Invalid deposit amount" << endl;
    }
}

int main() {
    deposit();

    return 0;
}

