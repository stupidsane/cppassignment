                                               //     Overloading + and == operator          //
                                             //                    for Strings                              //

#include <iostream>
#include <string>

using namespace std;

class stringmanip  {
private:
    string str;
public:
    stringmanip():str{NULL} { }
    void getdata() {
         cout<<"Enter string = ";
         cin>>str;
    }
    void showdata() {  cout << "String is "<<str<<endl;  }
   
    stringmanip operator+(const stringmanip rhs) {
        stringmanip temp;
        temp.str=(this->str)+rhs.str;
        return temp;
    }
    
    bool operator==(const stringmanip rhs) {
        if(str.compare(rhs.str)==0)
            return true;
        else
            return false;
    }
};

int main() {
    stringmanip S1,S2,S3;
    S1.getdata();    
    S2.getdata();
    S3=S1+S2;
    S3.showdata();
    if(S1==S2)
        cout<<"Strings are equal"<<endl;
    else
        cout<<"Strings are not equal"<<endl;
return 0;    
}