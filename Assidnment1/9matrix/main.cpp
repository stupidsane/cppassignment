#include <iostream>
#include <vector>

using namespace std;
class matrix;
class vectors {
      int vec[3];

public: 
     void getvector();
     void disvector();
     friend  void multiply(matrix &,vectors &);
     
};

class matrix {
private:
      int mat[3][3];

public:
     void getmatrix();
     void dismatrix();
     friend  void multiply(matrix &,vectors &);
};

//MEMBER FUNCTION OF VECTOR--->

void vectors::getvector() {
    for(int i=0;i<3;i++) {
           cout<<"Enter the vec ["<<i+1<<"] -->";
           cin>>vec[i];
    }
}

void vectors::disvector() {
     cout<<"VECTOR IS --> [ ";
    for(int i=0;i<3;i++) 
         cout <<vec[i]<<" ";
    cout<<"]\n"<<endl;
}

//MEMBER FUNCTION OF MATRIX--->

void matrix::getmatrix() {
     for(int i=0;i<3;i++) {
         for(int j=0;j<3;j++) {
             cout<<"\nEnter value mat[ "<<i<<"]["<<j<<"]---> ";
             cin>>mat[i][j];
         }
     }
}

void matrix::dismatrix() {
     cout<<"\nvalue of mat--->\n";
     for(int i=0;i<3;i++) {
         for(int j=0;j<3;j++) 
            cout<<mat[i][j] <<"  ";
            cout<<"\n";
     }
}

//FRIEND FUNCTION  --->

void multiply(matrix &mat1,vectors &vec1) {
    int res[3] {0};
     cout<<"\n value of  matrix*vector-->[";
     for(int i=0;i<3;i++) {
         for(int j=0;j<3;j++) 
            res[i]=res[i]+(vec1.vec[j]*mat1.mat[j][i]);
     }
      for(int i=0;i<3;i++) 
          cout << res[i]<<" ";
          cout <<"] "<<endl;
    
}

int main() {
    vectors vec1;
    matrix mat1;
    vec1.getvector();
    mat1.getmatrix();
    system("cls");
    vec1.disvector();
    mat1.dismatrix();
    multiply(mat1,vec1);
    return 0;
}

