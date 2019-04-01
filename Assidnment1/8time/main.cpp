#include<iostream>
using namespace std;
 
class Time
{
    private:
        int hh,mm;
    public:
        void getTime();
        friend Time add(Time,Time);
        void displayTime();
};
 
void Time::getTime()
{
     cout << "Enter hour:";
     cin   >>hh;
       cout << "Enter minutesr:";
     cin   >>mm;
}
 Time  add(Time T1,Time T2)
{
    Time temp;
    temp.mm=T1.mm+T2.mm;
    temp.hh=T1.hh+T2.hh+(temp.mm/60);
    temp.mm%=60;
    return temp;
}
 
void Time::displayTime()
{
    cout << "The added time is = " << hh << ":" << mm <<"\n"<< endl;
}
 
int main()
{
    Time T1,T2,T3; 
     cout << "Enter time T1:"<<endl;
    T1.getTime();
    cout << "\n\nEnter time T2:"<<endl;
    T2.getTime();
    T3=add(T1,T2);
    T3.displayTime();
     
    return 0;
}