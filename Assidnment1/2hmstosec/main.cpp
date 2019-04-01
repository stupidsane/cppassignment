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
        int seconds;
        string time;
        vector<string> times;
        int hh,mm,ss;
    public:
        void getTime();
        void convertIntoSeconds();
        void displayTime();
};
 
void Time::getTime()
{
     cout << "Enter time:";
     getline(cin,time);
     boost::split(times, time, boost::is_any_of(":"));
    if(times.size()==3)
    {
            hh = stoi(times.at(0));
            mm = stoi(times.at(1));
            ss = stoi(times.at(2));
    }
    
    else
    {
        cout<<"\nInvalid time entered....";
    }
    
}
 
void Time::convertIntoSeconds()
{
    seconds = hh*3600 + mm*60 + ss;
}
 
void Time::displayTime()
{
    cout << "The time is = " << setw(2) << setfill('0') << hh << ":"<< setw(2) << setfill('0') << mm << ":"<< setw(2) << setfill('0') << ss << endl;
    cout << "Time in total seconds: " << seconds<<endl;
}
 
int main()
{
    Time T; //creating objects
     
    T.getTime();
    T.convertIntoSeconds();
    T.displayTime();
     
    return 0;
}