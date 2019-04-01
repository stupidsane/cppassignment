                                                                  //               Class Type  to   another class type Conversion              //


#include <iostream>
#include <limits>

using namespace std;
class Civil_Time;
class Railway_Time {
private:
    int hh;
    int mm;

public:
    void getdata() {
        char temp;
        int i=0;
        while(i==0)  {
        cout << "Enter Railway Time : ";
        cin >> hh>>temp>>mm;
         if(cin.fail()||hh>23||mm>59||temp!=':')  {  
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout<<"wrong entry"<<endl;
            }
            else
             i=1;
        }
    
    }
    void show() {
        cout<<"Railway Time : "<<hh<<" : "<<mm<<endl;
    }
    int gethour() { return hh; }
    int getminutes() { return mm; }
};

class Civil_Time {
private:
    int hh;
    int mm;
    string meridiem;
public:
    Civil_Time() :hh{0},mm{0},meridiem{NULL} {  };
    void display() {
        cout << "Civil Time : "<<hh<<" : "<<mm<<" "<<meridiem<<endl;
    }
    Civil_Time(Railway_Time T) {
        this->hh=(T.gethour())%12;
        this->mm=T.getminutes();
        if(((T.gethour())/12)==0)
            meridiem="a.m.";
        else
            meridiem="p.m.";
    }
};

int main() {
    Railway_Time R1;
    Civil_Time C1;
    R1.getdata();
    C1=R1;
    C1.display();
    return 0;
}
