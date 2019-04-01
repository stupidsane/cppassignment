//  Assignment question number 3:
#include <iostream>
#include <regex>
#include <string>

   using namespace std;
    class bank{
    	private:
    	string depositer_name;
    	string acc_no;
    	int type_of_account;
    	double  balance;
    	float amount;
    	  public:
    	  	void assign(){
               regex RuleName("^[a-zA-Z ]*$");
               regex Ruleaccno("^[0-9]*$");
          //DEPOSITOR NAME
                do{
                cout<<"Enter  Depositor Name: ";
    	  		cin>>depositer_name;
                 if(!regex_match(depositer_name,RuleName))
                        cout<<"**Invalid Depositor Name**"<<endl;
                 }while(!regex_match(depositer_name,RuleName));
                 cin.ignore();
                 //ACC NO
    	  		do{
                cout<<"Enter account number:";
    	  		getline(cin,acc_no);
                 if(!regex_match(acc_no,Ruleaccno))
                      cout<<"**Invalid account number**"<<endl;
                 }while(!regex_match(acc_no,Ruleaccno));
                 //ACC TYPE
                 do{
    	  		cout<<"Enter Account Type : FOR 1.Saving /2.Current  ";
                cin>>type_of_account;
                 }while(type_of_account!=1&&type_of_account!=2);
                 
                 //ACC BALANCE
    	  		cout<<"Enter balance:";
    	  		cin>>balance;
    	  		 return;
			  }
		    void deposit(){
		    	
		    	cout<<"Enter amount to deposit:";
		    	cin>>amount;
		    	balance=balance+amount;
		    	return;
			}
			void withdrawl(){
				if(balance>0){
                do{
				cout<<"Amount available  , Enter amount to withdraw  :";
				cin>>amount;
                if(amount<0)
                    cout<<"amount is negative";
                }while(amount<0);
                }
				  else
				     cout<<"Amount unavailable:";
				balance=balance-amount;
				return;
			}
			void display(){
			   cout<<"The Name of the Depositor: "<<depositer_name<<endl;
			   cout<<"The Final Balance is : "<<balance;
               if(type_of_account==1)
               {
                   cout<<"Saving Account";
    
               }
               else if(type_of_account==2)
               {
                   cout<<"Current account";
               }
			   return;
			}
		    };
		    
		    
		       int main()
		          {
		          	bank object;
		          	object.assign();
		          	object.deposit();
		          	object.withdrawl();
		          	object.display();
		          	return 0;
				  }
