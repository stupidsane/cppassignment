#include <iostream>

using namespace std;

class count {
protected:
    int c;
public:
    count():c{0} { }
    count(int c_val) { c=c_val; }  
    void operator++() { ++c; }
};

class counter:public count {
public: 
    counter() {
        cout<<"Value of c : "<<c;
 }
 void operator--() { --c; }
};
int main() {
    counter test;
    ++test;
}
