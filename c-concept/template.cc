#include <iostream>

using namespace std;

template <class NADU>
class Print {

 private:
   NADU a;

 public:
  
    void set(NADU n){
       a = n;
     }
 
    void print(){
      cout<<a<<endl;
     }
};


int main(){

Print<int> P;
P.set(10);
P.print();


Print<double> D;
D.set(10.29);
D.print();

Print<char> C;
C.set('C');
C.print();

Print<string> S;
S.set("hello");
S.print();


return 0;
}
