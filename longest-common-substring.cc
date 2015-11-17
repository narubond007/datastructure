/* Longest common substring given two strings, O(n^3) */

#include <stdio.h>
#include <string.h>

int main(){

const char *outer = "vishambarnathan";
const char *inner = "nathbrahman";
//const char *outer = "victoria";
//const char *inner = "victoria";

int outer_len = strlen(outer);
int inner_len = strlen(inner);

for(int i=0; i<outer_len; i++) {
  for(int j=0; j<inner_len; j++) {

      if( outer[i] == inner[j]){
           int ki = i, count=0;
           while((outer[ki] == inner[j]) && (outer[ki] != '\0') && (inner[j] != '\0')) {
              count++;
              printf("%c",outer[ki]);
              ki++;
              j++;
            }
           printf("\n");
           j--;
       }
   }
}
}
