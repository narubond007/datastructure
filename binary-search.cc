#include <stdio.h>

int a[] = {2,31,63,70,90,127,137,270};

bool search(int element, int start, int end){

  bool result=false;
  int mid_point = (start + end)/2;
   
  if (element == a[mid_point]) {
      printf("Found \n");
      return true;
  } else if((end -start) <=1 ) {
      return false;
  } else if(element > a[mid_point]) {
         result = search(element, mid_point, end);
  } else if ( element < a[mid_point]) {
         result = search(element, start, mid_point);
  }
  return result;
}

int main(){

bool b = search(77,0,7);
if(!b) {
 printf("Not found \n");
}

return 0;
}
