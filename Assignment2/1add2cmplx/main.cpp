#include <iostream>
#include <regex>

using namespace std;

class Complex {
public:
     float real;
     float imag;
public:
     Complex();
     Complex(float num) ;
     Complex(float rel_val,float img_val);
     friend Complex* add(Complex &C1,Complex &C2);
     friend void display(Complex C);
}C;
//CONSTRUCTORS 

Complex::Complex() {
         real=0.0;
         imag=0.0;
}
     
Complex::Complex(float num) {
         real=num;
         imag=num;
}
     
Complex::Complex(float real_val,float imag_val) {
         real=real_val;
         imag=imag_val;
}
     
Complex* add(Complex &C1,Complex &C2) {
    C.real=C1.real+C2.real;
    C.imag=C1.imag+C2.imag;
    return (&C);
}

void display(Complex C) {
    cout<<C.real<<" + "<<C.imag<<"i"<<endl;
}

int main() {
    string real_val,imag_val;
    int real_var,imag_var;
    int i=0;
    regex expr("^[1-9]");
    Complex *C3;
    cout<< "Enter the complex nos."<<endl;
    do{
    cout<<"Enter Real Part-->";
    getline(cin,real_val);
    if(regex_match(real_val,expr)) {
    cout <<"\nEnter Imaginary part -->";
    getline(cin,imag_val);
    if(regex_match(imag_val,expr)) {
        i=1;
    }
    else 
         cout<<"Wrong Entry"<<endl;
    }
    else 
        cout<<"Wrong Entry"<<endl;
    }while(i==0);
    real_var=stoi(real_val);
    imag_var=stoi(imag_val);
    
    Complex C1(3.0);
    Complex C2(real_var,imag_var);
    C3=add(C1,C2);
    display(*C3);
    
    
}