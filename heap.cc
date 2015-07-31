/* Max heap */
#include <stdio.h>
#include <vector>

int count=0;
std::vector<int> arr;


void swap(int x, int y){
  int temp = arr[x];
  arr[x] = arr[y];
  arr[y] = temp;
}

void heapify(int count){

 //If element==root, return
  if(count==0) return;

 /*find parent */
 int parent = ((count%2)!=0) ? (count-1)/2 : (count-2)/2;
  
 //If element < parent; return
 // else swap the element with its parent and check if you can go up further.
 if( arr[count] < arr[parent] ) return;
 else swap(count, parent);
 
 heapify(parent);

}


void deheapify(int index){

  //If both the children are non-existent, the return
  if((2*index+1 > (count-1))  || (2*index+2 > (count-1))) return;
  
  //Find the max of the children
  int max_children_index;
  if(



}

void insert(int data){
 arr.push_back(data);
 heapify(count);
 count++;
}

void print(){

 for(int i=0; i<count; i++)
   printf("%d  ",arr[i]);

 printf("\n");
}

int main(){

insert(127);
insert(70);
insert(90);
insert(137);
insert(2);
insert(31);
insert(63);

printf("Heapified..Before sort \n");
print();

return 0;
}
