#include <iostream>
#include <regex>
#include <string>
using namespace std;

class student {
private:
   static int rollno;
    string name;
    int mark1;
    int mark2;
    int mark3;
    int total;
    int avg;
public:
    int getdata(int);
    void displaydata();
};
int student::rollno=0;
int student::getdata(int n) {
    string  diceexpr = "^[a-zA-Z ]*$";
     regex valexp(diceexpr);
    rollno=rollno+1;
    if(rollno>0&&rollno<n+1) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nEnter Name     :  ";
            getline(cin,name);
            if(regex_match(name,valexp)) {
                    cout << "\nEnter Mark1    :  ";
                    cin >>mark1;
                    cout << "\nEnter Mark2    :  ";
                    cin >>mark2;
                    cout << "\nEnter Mark3    :  ";
                    cin >>mark3;
                    if(mark1<100&&mark1>0&&mark2<100&&mark2>0&&mark3<100&&mark3>0) {
                                total=mark1+mark2+mark3;
                                avg=(float)total/3;
                    }
                    else {
                                cout<< "invalid entry"<<endl;
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                return -1;
                            }
             }
             else  {
                    cout<< "invalid entry"<<endl;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    return -1;
                    }
       }
    else  {
              cout<< "invalid entry"<<endl;
              cin.ignore(numeric_limits<streamsize>::max(), '\n');
              return -1;
            }
            return 0;
}

void student::displaydata() {
    cout <<"\nRollno      :"<<rollno;
    cout <<"\nName        :"<<name;
    cout <<"\nMark1       :"<<mark1;
    cout <<"\nMark2       :"<<mark2;
    cout <<"\nMark3       :"<<mark3;
    cout <<"\nTotal       :"<<total;
    cout <<"\nAverage     :"<<avg<<endl;
}

int main() {
    student s[10];
    int temp=1;
    int n=0;
    do {
    cout << "\nEnter no of student :  ";
    cin >>n;
    for(int i=1;i<n+1;i++) {
        if(temp==1) {
         cout << "Enter the Data of student :"<<i<<endl;
    temp=s[i].getdata(n);
        }
    }
    if(temp==1) {
     for(int i=1;i<n+1;i++) {
          cout<<"\nDetails of STUDENT "<<i<<endl;
         s[i].displaydata();
     }
    }
    }while(temp!=1);
    return 0;
}