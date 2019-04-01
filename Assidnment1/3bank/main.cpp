# include <iostream>
# include <conio.h>
# include <iomanip>
# include <vector>
using namespace std;

class bank {
    string names;
    vector<string> name;
    int acno=0;
    string actype;
    float balance=0;
public:
    void init();
    void deposit();
    void withdraw();
    void disp_det();
    };
//member functions of bank class

void bank :: init()
{
cout<<"New Account"<<endl;
cout<<"Enter the Name of the depositor : ";
cin>>names;
cout<<"Enter the Account Number : ";
cin>>acno;
cout<<"Enter the Account Type (CURR/SAVG/FD/RD/DMAT)  :  ";
cin>>actype;
cout<<"Enter the Amount to Deposit : ";
cin >>balance;
}

void bank :: deposit()
{
float more;
cout <<"Depositing\n";
cout<<"Enter the amount to deposit : ";
cin>>more;
balance+=more;
}
void bank :: withdraw()
{
float amt;
cout<<"Withdrwal";
cout<<"Enter the amount to withdraw : ";
cin>>amt;
if(amt>balance&&amt>0)
    balance-=amt;
else
    cout<<"Invalid withdraw amount";
}
void bank :: disp_det()
{
cout<<"Account Details"<<endl;
cout<<"Name of the depositor : "<<names<<endl;
cout<<"Account Number        : "<<acno<<endl;
cout<<"Account Type          : "<<actype<<endl;
cout<<"Balance               : "<<balance<<endl;
}



int main(void)
{
bank obj;
int choice  =1;
while(choice!=0)
{
cout<<"Enter 0 to exit\n1. Initialize a new acc.\n2. Deposit\n3.Withdraw\n4.See A/c Status\n";
cin>>choice;
switch(choice)
{
    case 0 :obj.disp_det();
        cout<<"EXITING PROGRAM.";
        break;
    case 1 : obj.init();
        break;
    case 2: obj.deposit();
        break;
    case 3 : obj.withdraw();
        break;
    case 4: obj.disp_det();
        break;
    default: cout<<"Illegal Option"<<endl;
}
}
getch();
}

