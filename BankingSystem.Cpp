#include <iostream>
#include <cstdlib> 
using namespace std;

class Bank
{
private:
    int Total_bal = 1000;
    int choice, Deposit_Amount,credit_Amount;

public:
    int pin, flag = 1, Acc_No, Enter_Acc_No, Check_pin;
    string Acc_Name;

public:
    void Login()
    {
        do
        {
            cout << "Welcome:" << Acc_Name << endl;
            cout << "Enter Your Account Number: ";
            cin >> Enter_Acc_No;
            if (Enter_Acc_No == Acc_No)
            {
                cout << "Enter Your Pin: ";
                cin >> Check_pin;
                if (Check_pin != pin)
                {
                    flag++;
                    cout << "Enter Valid Pin... You have " << 3 - flag << " chances left" << endl;
                }
                else
                {
                    options();
                }
            }
            else{
                cout<<"Invalid Acc number..";
            }
        } while (flag < 3);
    }

public:
    void open_Account() {
        cout << "WELCOME TO OUR ACCOUNT Opening" << endl;
        cout << "Enter Your Name To register: ";
        cin >> Acc_Name;
        cout << "Enter your pin:";
        cin >> pin;
        if (pin >= 1000 && pin <= 9999) {
            while (true){
                Acc_No = rand() % 900000000 + 100000000;
                cout << "Your ACC number is: " << Acc_No << endl;
                Login();
                break;
            }
        } else {
            cout << "Please Enter a Valid Pin between 1000 and 9999" << endl;
        }
    }


    void options()
    {
        do
        {
            cout << "Enter Your choice \n 1-deposit \n 2-credit \n 3-check_bal \n 4-mini-statement \n 9-for exit \n";
            cin >> choice;
            if (choice == 1)
            {
                deposit();
            }
            else if (choice == 2)
            {
                credit();
            }
            else if (choice == 3)
            {
                check_Balance();
            }
            else if (choice == 4)
            {
                mini_Statement();
            }
            else
            {
                cout << "Invalid input" << endl;
            }
        } while (choice != 9);
    }

    void deposit()
    {
        cout << "Enter How much amount you want to Deposit: ";
        cin >> Deposit_Amount;
        if(Deposit_Amount<=Total_bal){
        Total_bal = Total_bal - Deposit_Amount;
        cout << "Deposited successfully. Your new balance is: " << Total_bal << endl;
        }
        else{
            cout<<"Insufficient balance";
        }
    }

    void credit()
    {
        cout << "Enter How much amount you want to credit: ";
        cin >> credit_Amount;
        Total_bal = Total_bal + credit_Amount;
        cout << "Amount credited successfully. Your new balance is: " << Total_bal << endl;
    }

    void check_Balance()
    {
        cout << "Your balance is: " << Total_bal << endl;
    }

    void mini_Statement()
    {
        cout<<"You have deposited:"<<Deposit_Amount<<endl;
        cout<<"You have credited:"<<credit_Amount<<endl;
        cout<<"Your Total Balance:"<<Total_bal<<endl;
    }
};

int main()
{
    Bank a;
    cout << "Welcome TO Lena dena Bank" << endl;
    cout << "Register Yourself by pressing 1, or press 2 to exit: ";
    int choose;
    cin >> choose;

    if (choose == 1)
    {
        a.open_Account();
    }
    else if (choose == 2)
    {
        cout << "Thank you..." << endl;
        return 0;
    }
    else
    {
        cout << "Invalid Choice" << endl;
    }

    return 0;
}
