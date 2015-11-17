//Typically, stl priority_queue are max heap. But they can used as a min heap by doing a simple tweak.

#include <queue>
#include <iostream>
  
using namespace std;
  
struct comparator {
 bool operator()(int i, int j) {
 return i > j;
 }
};
  
priority_queue<int, std::vector<int>, comparator> minHeap;

void print(){

  if(minHeap.empty()) return;
  int i = minHeap.top();
  cout<< i << " ";
  minHeap.pop();
  print();
  minHeap.push(i);

}
  


int main(int argc, char const *argv[])
{
  
 minHeap.push(10);
 minHeap.push(5);
 minHeap.push(12);
 minHeap.push(3);
 minHeap.push(3);
 minHeap.push(4);

 //for every number, pop a number and insert a new number, then print the queue
 int num;
while(1){
 cin>>num;
 if(num > minHeap.top()){
  minHeap.pop();
  minHeap.push(num);
 } 

 print();
 cout << endl; 

}
 return 0;
}
