/* String reverse
   To upper
*/
#include <stdio.h>
#include <string.h>

void reverse(char *str){

 int len = strlen(str);
 for(int i=0; i<len/2; i++){
  
   //swap str[i[ and str[len-1-i]
   char temp = str[i];
   str[i] = str[len-1-i];
   str[len-i-1] = temp;

 }

 printf("Reversed string is %s \n",str);

}


void toUpper(char *str){

 int len = strlen(str);
 
 //check if each char falls in the lower range, only then swap, else leave it.
 
 for(int i=0; i<len; i++){

  if((str[i] >= 97) && (str[i] <= 122)){
    str[i] =  str[i] - 32;
  }

 }

 printf("To uppered string is %s \n",str);

}


int main(){

char p[100] = "This Is Sparta";
reverse(p);


return 0;
}
