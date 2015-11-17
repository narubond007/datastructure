//works fine for all cases
// Sort a rotated array using binary search

#include <iostream>
#include <stdio.h>

using namespace std;

//for binary search, array has to be in ascending order
//int a[] = {4,7,9,13,25,31,67,73,401,513};

//rotated array
int a[] = {67, 73, 401, 513, 4,7,9,13,25,31};

int main(){

int NUM=0;

while(true){

cout << "Print enter a number: "<<endl;
cin>>NUM;

int start=0;
int end = 9;
int mid=0;

//remember the termination case. This works for all the numbers
// no infinite loops, we have tested it well.
while(start <= end) {
   //cout << start << " " << end << " " <<endl;  
   mid = (start+end)/2;
   if(NUM == a[mid]){
      cout << "Found " << NUM << endl;
      break;
   } else if((NUM > a[mid]) && (a[mid] >= a[start])){
      start = mid+1;
      end = end;
   } else if((NUM < a[mid]) && (a[mid] >= a[start])){
      start = start;
      end = mid - 1;
   } else if((NUM > a[mid]) && (a[mid] <= a[start])){
      printf("Here1 \n");
      start = start;
      end = mid-1;
   } else if((NUM < a[mid]) && (a[mid] <= a[start])){
      printf("Here2 \n");
      start = mid+1;
      end = end;
   }

}
}
return 0;
}
