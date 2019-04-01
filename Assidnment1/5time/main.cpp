#include<iostream>
#include<conio.h>
#include<vector>
#include<cstring>
#include<bits/stdc++.h>
#include<string>
#include<boost/algorithm/string.hpp>
using namespace std;
 
class Time
{
    private:
        string time;
        vector<string> times;
        int hh,mm;
    public:
        void getTime();
        void add(Time,Time);
        void displayTime();
};
 
void Time::getTime()
{
     cout << "Enter time:";
     getline(cin,time);
     boost::split(times, time, boost::is_any_of(":"));
    if(times.size()==2)
    {
            hh = stoi(times.at(0));
            mm = stoi(times.at(1));
    }
    
    else
    {
        cout<<"\nInvalid time entered....";
    }
    
}
 
void Time::add(Time T1,Time T2)
{
    mm=T1.mm+T2.mm;
    hh=T1.hh+T2.hh+(mm/60);
    mm%=60;
}
 
void Time::displayTime()
{
    cout << "The added time is = " << setw(2) << setfill('0') << hh << ":"<< setw(2) << setfill('0') << mm << endl;
}
 
int main()
{
    Time T1,T2,T3; //creating objects
     
    T1.getTime();
    T2.getTime();
    T3.add(T1,T2);
    T3.displayTime();
     
    return 0;
}