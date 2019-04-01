#include <iostream>
#include <string>

using namespace std;

class user {
public:
    string name;
    int age;
public:
    user(string name_val,int age_val) {
        name=name_val;
        age=age_val;
    }
};

class student: public user {
private:
    string course;
    int roll_no;
    int marks;
public:
    void get_details() {
        cout<<"Enter The Data of Student : "<<"\nEnter The Course : ";
        getline(cin,course);
        cout<<"Enter Roll No : ";
        cin>>roll_no;
        cout<<"Enter marks : ";
        cin>>marks;
    }
    
    void display() {
        cout<<"Name of Student : "<<name<<"\nAge : "<<age<<"\nCourse : "<<course<<"\nRoll No : "<<roll_no<<"\nMarks : "<<marks<<endl;
    }
    user(string name_val,int age_val) {
        name=name_val;
        age=age_val;
        get_details();
       display(); 
    }
};

class teacher: public user {
private:
    string subj_assign;
     int contact_hour;
public:
     void get_details() {
        cout<<"Enter The Data of Student : "<<"\nEnter The Subjects assigned : ";
        getline(cin,subj_assign);
        cout<<"Enter contact_hour : ";
        cin>>contact_hour;
     }
     void display()  {
         cout<<"The Subjects assigned to "<<name;
         cout<<subj_assign<<"Contact Hour : "<<contact_hour;
     }
       user(string name_val,int age_val) {
        name=name_val;
        age=age_val;
        get_details();
       display(); 
    }
};

int main()  
     user s("abhay",21);
  /*  int choice;
    cout<<"Enter choice :\n1: Student\n2: Teacher"<<endl;
    cin>>choice;
    switch(choice)  {
        case 1: user S("abhay",21);
                     break;
        case 2: user T("Rishi",45);
                    break;
        default: cout<<"Wrong Entry";
                    break;
    }*/
}