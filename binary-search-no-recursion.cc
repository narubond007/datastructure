#include <iostream>

using namespace std;

//for binary search, array has to be in ascending order
int a[] = {4,7,9,13,25,31,67,73,401,513};

int main(){

int NUM=0;

int start=0;
int end = 9;

int mid = (start + end)/2;

//remember the termination case. This works for all the numbers
// no infinite loops, we have tested it well.
while(start <= end) {
  
   if(NUM == a[mid]){
      cout << "Found " << NUM << endl;
      break;
   } else if( NUM > a[mid]){
      start = mid+1;
      end = end;
   } else if( NUM < a[mid]){
      start = start;
      end = mid - 1;
   }
   mid = (start+end)/2;
}

return 0;
}
