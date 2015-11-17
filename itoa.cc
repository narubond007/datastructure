#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char * itoa(int num){

  char *result = (char *)malloc(sizeof(char) * 11);
  int i=0;
 
  while((num != 0) && (i<= 10)){
   result[i] = (num%10) + '0';
   num = num/10;
   i++;
  }
  result[i] = '\0';

  int len = strlen(result);
  if(len <= 1) return result;
  
  for(i=0; i<len; i++) {
     char temp = result[i];
     result[i] = result[len-1-i];
     result[len-1-i] = temp;
  }
  return result;
}


int main(){

int num = 5;
char *s = itoa(num);
printf("%s ",s);
free(s);
return 0;

}
