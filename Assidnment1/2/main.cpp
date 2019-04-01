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
    int hour,minute,second;
    public:
        bool is_hour(int hour);
        bool is_minute(int minute);
        bool is_second(int second);
        void is_valid(string str);
        void convert(string str);
        long hms_to_secs(int hour, int minute, int second);
};

//void Time::is_valid(string str)
//{
//
//}


bool Time::is_hour(int hour)
{
    if(hour<=12 && hour >0)
    {
        return true;
    }
    else
        return false;
}

bool Time::is_minute(int minute)
{
    if(minute<=59 && minute>0)
    {
        return true;
    }
    else
        return false;
}

bool Time::is_second(int second)
{
    if(second<=59 && second>0)
    {
        return true;
    }
    else
        return false;
}

long Time::hms_to_secs(int hour, int minute, int second)
{
    if(is_hour(hour))
    {
        if(is_minute(minute))
        {
            if(is_second(second))
            {
                return (second+(minute*60)+(hour*60*60));
            }
            else
            {
                cout<<"\nInvalid second.......";
                return -1;
            }
        }
        else
        {
            cout<<"\nInvalide minute......";
            return -1;
        }
    }
    else
    {
        cout<<"\nInvalid hour.......";
        return -1;
    }
}

void Time::convert(string str)
{
    vector<string> result;
    boost::split(result, str, boost::is_any_of(":"));
    if(result.size()==3)
    {
           int hour = atoi(result[0].c_str());
           int minute = atoi(result[1].c_str());
           int second = atoi(result[2].c_str());
    }
    
    else
    {
        cout<<"\nInvalid time entered....";
    }
    
    cout<<"\nafter conversion: "<<hms_to_secs(hour,minute,second);
    
}

int main()
{
    Time obj;
    string str;
    cout<<"\nEnter you number in the format hh:mm:ss : ";
    getline(cin,str);
    obj.convert(str);
    cout<<"value in seconds: "<<obj.hms_to_secs(11,65,10)<<endl;
    return 0;

}
