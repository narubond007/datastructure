#include <stdio.h>
#include <string.h>



//complexity = 0(n^2) :  Abhinav doesnt like
bool substr_by_brute_force(const char *src,const  char *pattern){

   bool ret= false;

   size_t srclen = strlen(src);
   size_t patternlen = strlen(pattern);
   int j=0;

   for(size_t i=0;i<srclen;i++){
     j = 0;
     
     //If pattern[0] matches src[i], then start a for loop iterating pattern string.
     if(src[i] == pattern[j]){
        size_t k = i;
        for(j=0; j<patternlen; j++){
           if((pattern[j] == src[k])&& (k < srclen)) { k++;}
           else {break; }
        }
        if(j == patternlen) return true;
     }
    }
   return false;
}


int main(){


//const char *src = "ABC ABCDAB ABCDABCDABDE";
//const char *pattern = "ABCDABD";

const char *src="chaluwashghanshyamwashingpowder";
const char *pattern="washing";

bool ret = substr_by_brute_force(src, pattern);

if(ret == true) { printf("Found \n"); }
else { printf("Not Found \n"); }

return 0;
}
