#include <iostream>

void split(int arr[], int left, int right){

  if((right - left) == 0) return;
  
  split(left, (left+right)/2);
  split((left+right)/2 + 1, right);

  merge(arr, left, (left+right)/2, (left+right)/2 + 1, right); 

}

void merge(int arr[], int llb, int lub, int rlb, int rub) {


   for(int i=llb, i<= lub; i++)




}
