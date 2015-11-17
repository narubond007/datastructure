#include <iostream>
// Given a child c, its parent = (c-1)/2
// Given a parent p, its childrwn are 2p+1, 2p+2

using namespace std;

//step 1: construct the heap
// step 2: sift-down or deheapify


int a[] = {127,70,90,137,2,65,37};
//int a[] = {1,2,3,4,5,6,7};

void print(){
//print the heap
for(int i=0;i<7; i++)
 cout<< a[i] <<" ";

cout<<endl;
}

void heapify(int a[], int child, int parent){

  while(a[child] > a[parent]){
   //swap a[i] and a[parent]
   int temp = a[parent];
   a[parent] = a[child];
   a[child] = temp;

   child = parent;
   parent = (parent-1)/2;
  }
}

void createHeap(){

  int i=1;

  for(int i =1; i<7; i++){
    heapify(a,i, (i-1)/2);
  }
}

void deheapify(int a[], int end){

   int i=0;
   int lchild = 2*i+1;
   int rchild = 2*i+2;
 
  while((lchild <= end) && (rchild <= end)){

  //find who is greater child: left or right
  int greater_child_index = (a[lchild] > a[rchild]) ? lchild : rchild;
  //amongst the greater children, see if a[i] is great or not
 
  if(a[i] < a[greater_child_index]){
    int temp = a[i];
    a[i] = a[greater_child_index];
    a[greater_child_index] = temp;
  }

   i = greater_child_index; 
   lchild = 2*i+1;
   rchild = 2*i+2;
}
}

void sortInAscending(){

  for(int i=6; i>=0; i--){
    //swap ith element with first element, then deheapify again
    int temp = a[0];
    a[0] = a[i];
    a[i] = temp;
    deheapify(a,i-1);
    print();
  }
}

int main(){

createHeap();
sortInAscending();
print();

return 0;
}
