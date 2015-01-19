/* Task one- find the partition element. Given an array, first element, 
   last element, return the partition index. 
   The partition index is an index which is in sorted position.

   Again apply quick sort before an after the partition

   Quick sort function is recursive. The first step is to find the partition index. 
   Second step is partition the array and call quick sort on sub arrays.
   http://www.cise.ufl.edu/~ddd/cis3020/summer-97/lectures/lec17/sld001.htm
*/
#include <stdio.h>

//int a[] = {127, 70, 90, 137, 2, 31, 63};
//int a[] = {2, 31, 63, 70, 90, 127, 137};
//int a[] = {137, 127, 90, 70, 63, 31, 2};
//int a[] = {4,4,4,4,4,4,4};
int a[] = {137, 127, 88, 137, 70, 70, 127};

//swap
void swap(int *array, int index1, int index2){
   int temp = array[index1];
   array[index1] = array[index2];
   array[index2] = temp;
}

//partition
int partition(int *array, int first, int last){

   //Initialise the pivot to be the first element.
   int pivot= first;

   int up=first, down=last, i=0;

while(down > up)
 {
   //Move right from first element, stop when any element > pivot OR you have reached the end.
   for(i=up; i<=last; i++){
     if( a[i] > a[pivot]) break;
   }
   //If up reached till the end of the array, then up=last or up=i 
   up = (i > last) ? last : i;

   //Move left from last element, stop when any element <= pivot OR you have reached the beginning.
   for(i=down; i >= first; i--){
     if( a[i] < a[pivot]) break;
   }
   
   //If we reached till the beginning of the array, then down=first or down=i
   down = (i < first) ? first : i; 

   if(down > up){
    swap(array, up, down);
   }

} 

//swap down and pivot
swap(array, pivot, down);

//return the "down" element. This is the partition
return down;
}  

//print  
void print(int *array, int first, int last){
 printf("first: %d, last: %d   ",first, last);
 for(int i=first; i<=last; i++){
   printf("%d ", a[i]);
 }
  printf("\n-------------------\n");
}

//quicksort 
void quicksort(int *array, int first, int last){

  print(array, first, last);
  if(first >= last) return;
  int partition_index = partition(array, first, last);
  printf("partition index = %d \n", partition_index);
  quicksort(array, first, partition_index-1);
  quicksort(array, partition_index+1, last);

}

int main(){

  quicksort(a, 0, 6);
  print(a, 0, 6);
  return 0;

}   

