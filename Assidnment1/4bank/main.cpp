
  // Banking program with username and password 

#include <iostream>
#include <string>
#include <regex>
#include <boost/algorithm/string.hpp>
#include <limits>
#include <cstring>

using namespace std;

//CLASS 

class Account{
    
    string UserName;
    string Password;
    string AccountNumber;
    string AccountType;
    double balance;
    float interest;
    double interest_val;
    
public:

// FUNCTION DECLARATION
    
    Account():UserName{"NA"}, AccountNumber{"NA"},AccountType{"NA"},balance{0}{
        
    }
    string AccountTypeMenu(); 
    void setdata(string UserName,string Password,string AccountNumber,double value);
    void deposite(double value);
    void withdraw(double value);
    void display();
    
    
    
};

// FUNCTION DEFINATION
    
string Account::AccountTypeMenu()
{
    char selection {};
    cout<<"\nChoose Account Type:\n"
        <<"S: Savings\n"
        <<"C: Current\n"
        <<"L: Salary\n";
    cin>>selection;
    switch(selection)
    {
        case 's':
        case 'S':
        interest=0.06;
        return "Savings";
        break;
        
        case 'c':
        case 'C':
        interest=0.04;
        return "Current";
        break;
        
        case 'l':
        case 'L':
        return "Salary";
        break;
        
        default:
        cout<<"Invalid choice. Account type set to NA";
        return "NA";
        break;
    }
}

//TO SET USER DETAILS
    
void Account::setdata(string UserNameVal,string PasswordVal,string AccountNumberVal,double value)
{
    Password=PasswordVal;
    UserName=UserNameVal;
    AccountNumber=AccountNumberVal;
    AccountType=AccountTypeMenu();
    balance=value;
}

//TO DEPOSIT
    
void Account::deposite(double value)
{
    if(value<0)
    {
        cout<<">>Deposite money is negative."<<endl;
    }
    else
    {
        balance+=value;
        cout<<"\n"<<value<<" added to account number "<<AccountNumber<<endl;
        cout<<"\nUpdated balance: "<<balance<<endl;
    }
}

//TO WITHDRAW 
    
void Account::withdraw(double value)
{
    if(value<0)
    {
        cout<<"\n***Entered value is negative.*"<<endl;
    }
    else
    {
        if(value>balance)
        {
            cout<<"\n\n***Insufficient amount*"<<endl;
        }
        else
        {
        balance-=value;
        cout<<"\n"<<value<<" has been withdrawn from account of "<<UserName<<endl;
        cout<<"\nUpdated balance: "<<balance<<endl;
        }
    }
}

//TO DISPLAY DETAILS
    
void Account::display()
{
    cout<<"====================================="<<endl;

    cout<<"\nDetails of user:"<<endl;
    cout<<"\nAccount Number: "<<AccountNumber;
    cout<<"\nUserName: "<<UserName;
    cout<<"\nAccount Type: "<<AccountType;
    cout<<"\nBalance: "<<balance;
}

                                                            //MAIN FUNCTION
int main()
{
    regex RuleName("^[a-zA-Z ]*$");
    regex RulePassword("^[a-zA-Z ]+$");
    char choice {'0'};
    Account obj;
    string UserName,AccountNumber,Password;
    double balance,DepositeMoney {}, WithdrawMoney {};
     cout<<"Welcome to XYZ bank,\n";
    do{
       cout<<"\n===================================\n"
            <<"\nPlease select a service: \n\n"
            <<"I: Set intial values of account\n"
            <<"D: Deposite money\n"
            <<"W: Withdraw money\n"
            <<"S: Display deatails\n"
            <<"Q: Quit\n\n";
    cout<<"Your choice: ";
    cin>>choice;
    switch(choice)
        {
        case 'i':
        case 'I':
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            do{
            cout<<"\nEnter your UserName: ";
            getline(cin,UserName);
            if(!regex_match(UserName,RuleName))
                cout<<"**Invalid username**"<<endl;
            }while(!regex_match(UserName,RuleName));
            
            do{
            cout<<"\nEnter your Password: ";
            getline(cin,Password);
            if(!regex_match(Password,RulePassword))
                cout<<"**Invalid Password**"<<endl;
            }while(!regex_match(Password,RulePassword));
            
            cout<<"\nEnter Account Number: ";
            getline(cin,AccountNumber);
            cout<<"\nEnter amount to be set: ";
            cin>>balance;
            obj.setdata(UserName,Password,AccountNumber,balance);
            
            
            break;
            
        case 'd':
        case 'D':
            cout<<"\nEnter the amount to be deposited: ";
            cin>>DepositeMoney;
            obj.deposite(DepositeMoney);
            break;
            
        case 'w':
        case 'W':
            cout<<"\nEnter the amount to be withdrawn: ";
            cin>>WithdrawMoney;
            obj.withdraw(WithdrawMoney);
            break;
            
        case 's':
        case 'S':
            obj.display();
            break;
            
            
        case 'q':
        case 'Q':
            cout<<"\n*Thanks for using for our service.\nWish you a great day ahead.*"<<endl;
            break;
            
            
        default: 
            cout<<"Invalid choice";
            break;
        
        }
    
    }while((choice!='q')&&(choice!='Q'));
    
    cout<<endl;
    return 0;
}