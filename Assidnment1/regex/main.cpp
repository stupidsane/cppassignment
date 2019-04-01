#include <iostream> 
#include <regex> 
  
using namespace std; 
int main() 
{ 
     regex valexp1("^[a-zA-Z ]+");
     regex valexp2("^[0-9. ]+");
     string name;
     do{
     cout << "\nEnter Name     :  ";
            getline(cin,name);
             if(regex_match(name,valexp2))  {
                  cout<<"true"<<endl;
             }
            else
                cout<<"false"<<endl;
     }while(true);
    return 0; 
} 