#include <iostream>
#include <limits>

using namespace std;
class exam;

class student {
    friend class exam;
private:
    int rollno;
    string name;
    string course;
public:
    void input_student()  {
        
        cout<< "Enter Name : ";
        getline(cin,name);
        cout<< "Enter Course : ";
        getline(cin,course);
    }
    void display_student()  {
        cout<<name<<"\t";
        cout<<course<<endl;
        
    }
};

class exam:public student  {
private:
    int mark1,mark2,mark3;
public:
    void input_marks()  {
        input_student();
        int i=0;
        while(i==0)  {
        cout<<"Enter marks : ";
        cin>>mark1>>mark2>>mark3;
         if(cin.fail()){  
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout<<"wrong entry"<<endl;
            }
            else 
                i=1;
        }
    }
    void display_result()  {
        display_student();
        cout<<"Marks are  "<<mark1<<"  " <<mark2<<"  "<<mark3<<endl;
        }
};

int main()  {
    exam S[5];
    for(int i=0;i<2;i++) {
        cout<<"Details of Student  "<<i+1<<":  "<<endl;
        S[i].input_marks();
        cin.ignore();
    }
    system("cls");
     for(int i=0;i<2;i++) {
         cout<<"Details of Student  "<<i+1<<":  "<<endl;
        S[i].display_result();
    }
}