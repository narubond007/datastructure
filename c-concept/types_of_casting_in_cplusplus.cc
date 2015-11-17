#include <stdio.h>

int main(){

const int c=3;

// c is a const and you want to remove the constness
int &i = const_cast<int &>(c);
//int &i = c;
i = 5;
printf("%d \n",i);
return 0;

}
