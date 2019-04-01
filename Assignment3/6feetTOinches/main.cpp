                                   //     Overload < and += operator for       //
                                 //           Distance in feet and inches          //


#include <iostream>
#include <limits>

using namespace std;

class Distance {
private:
    int feet;
    int inches;
    float meter;
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
    int getfeet() {  return feet;  }
    int getinches() {  return inches;  }
    operator float()  {  return meter;  }
};

int main() {
    Distance D1;
    float meters;
    meters=((D1.getfeet()*12)+D1.getinches())*0.254;
    D1.getdata();    
    system("cls");
    D1.show();

    cout<<"  equals to "<<meters<<" meters";
    cout<<endl;
    return 0;
}