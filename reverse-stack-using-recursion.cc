//Reverse a stack in place using push/pop operations only

//Printing a stack is also tricky- You need to use recursion. You cannot directly iterate over the stack

#include <iostream>
#include <stack>

using namespace std;

stack<int> myStack;

void insertAtBottom(int i){

   if(myStack.empty()) {
      myStack.push(i);
   } else {
     
      int temp = myStack.top();
      myStack.pop();
      insertAtBottom(i);
      myStack.push(temp);
   } 


}

void reverseStack(){

  if(myStack.empty()) return;
  int  i = myStack.top();
  myStack.pop();
  reverseStack(); 
  insertAtBottom(i);
}

void printStack(){

  if(myStack.empty()) return;
  int i = myStack.top();
  myStack.pop();
  printStack();
  cout << i << " ";
  myStack.push(i);
}

int main(){

  myStack.push(1);
  myStack.push(2);
  myStack.push(3);

  printStack();
  cout<<endl;

  reverseStack();

  printStack();
  cout<<endl;

return 0;
}
