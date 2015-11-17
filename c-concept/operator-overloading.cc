#include <iostream>

using namespace std;

class MyService {

public:
  int m_a;

  void operator + (const MyService &A){
  cout << "Overloaded the + operator " <<endl;
//  return *this;
  }

};


int main(){
  MyService X;
  MyService Y;
  MyService Z;
  Z = X + Y;
  return 0;
}


















