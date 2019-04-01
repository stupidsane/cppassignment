                                       //        Adding Two complex number         //
                                     //            By overloading + operator          //

#include <iostream>
#include <limits>

using namespace std;
class Complex {
    friend Complex operator+(const Complex &lhs,const Complex &rhs);
private:
    float real;
    float img;
public:
   Complex():real{0.0},img{0.0} { }
  void getdata();
   void showdata() {
       cout<<"Complex No. :    "<<real<<"+"<<img<<"i"<<endl;
   }
  /* Complex operator+(const Complex C) {
        Complex temp;
        temp.real=real+C.real;
        temp.img=img+C.img;
        return temp;
    } */
    
};

 void Complex::getdata() {
     int i=0;
       while(i==0) {
          cout<<"Enter Real part : ";
          cin>>real;
          if(cin.fail()){  
             cin.clear();
             cin.ignore(numeric_limits<streamsize>::max(),'\n');
             cout<<"wrong entry"<<endl;
          }
          else
                 i=1;
       }
       i=0;
        while(i==0)  {      
              cout<<"Enter Img part : ";
              cin>>img;          
              if(cin.fail())  {
                  cin.clear();
                  cin.ignore(numeric_limits<streamsize>::max(),'\n');
                  cout<<"wrong entry"<<endl;
               }
               else
                 i=1;
        
            }
}
Complex operator+(const Complex &lhs,const Complex &rhs) {
       Complex temp;
        temp.real=lhs.real+rhs.real;
        temp.img=lhs.img+rhs.img;
        return temp;
 }
 
 // MAIN FUNCTION
 
int main() {
    Complex C1,C2,C3;
    C1.getdata();
    C2.getdata();
    C3=C1+C2;
    system("cls");
    C1.showdata();
    C2.showdata();
    C3.showdata();
    return 0;

}