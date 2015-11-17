/* O(n^2) */

#include <stdio.h>
#include <string.h>

//char a[]="bananas";
char a[] = "forgeeksskeegfor";
//char a[] = "abaccddccefe";
//char a[] = "malayalam";
//char a[] = "HYTBCABADEFGHABCDEDCBAGHTFYW1234567887654321ZWETYGDE";
//print the palindrome
//char a[] = "bananananananagoopilalal";
//char a[] = "zabcdcbabcdcby";
//char a[] = "xabababa";


void print(char *a, int j, int i){
  for(int k=j; k<=i; k++){
    printf("%c", a[k]);
  }
  printf("\n");
}

int expand(char *a, int k, int l){

    int i=k, j=l;
    while(((a[i] == a[j]) && (j >= 0)) && (i<strlen(a))) {

      //print the palindrome
      print(a, j, i);
     
      int length = i-j+1;
      printf("Length of the palindrome is %d \n", length);
  
      i++;
      j--;
   }
  
  return i-1;  
}

int main(){

int j=0;
//Given an index i, find the smallest palindrome i.e a[i] == a[i-1] OR a[i] == a[i-2]
// Then try to expand it and see if you can find larger palindromes.
for(int i=1; i < strlen(a); i++){

   if((a[i] == a[i-1]) && (i>0)) {
     j = expand(a, i, i-1);
   }
   if((a[i] == a[i-2]) && (i>=2)) {
     j = expand(a, i, i-2);
   }
}

return 0;
}
