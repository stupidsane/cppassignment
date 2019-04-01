                                   //     Overload < and += operator for       //
                                 //           Distance in feet and inches          //


#include <iostream>
#include <limits>

using namespace std;

class Distance {
private:
    int feet;
    int inches;
public:
    Distance(): feet{0},inches{0} { }
    void getdata() {
        int i=0;
        while(i==0)  {
            cout<<"Enter Feets : ";
            cin>>feet;
            if(cin.fail()){  
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout<<"wrong entry"<<endl;
            }
            else 
                i=1;
        }
        i=0;
        while(i==0) { 
            cout<<"Enter Inches : ";
            cin>>inches;
            if(cin.fail()||inches>12)  {  
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout<<"wrong entry"<<endl;
            }
            else
             i=1;
        }
   }
     void show() {
            cout<<feet<<" feet "<<inches<<" inches";
     }
    bool operator<(const Distance rhs) {
        int lhs_inch,rhs_inch;
        lhs_inch=feet*12+inches;
        rhs_inch=rhs.feet*12+rhs.inches;
        if(lhs_inch<rhs_inch)
              return true;
        else 
              return false;
 }
 
  void operator+=(Distance rhs) {
      inches=inches+rhs.inches;
      feet=feet+rhs.feet+(inches/12);
      inches=inches%12;
  }
};

int main() {
    Distance D1,D2;
    D1.getdata();    
    D2.getdata();  
    system("cls");
    D1.show();
    cout<<endl;
    D2.show();
    cout<<endl;  
    if(D1<D2) { 
        D2.show();
        cout<<" is greater than ";
        D1.show();
    }
    else  { 
        D1.show();
        cout<<" is greater than ";
        D2.show();
    }
    D1+=D2;
    cout<<endl;
    D1.show();
    cout<<endl;
    return 0;
}