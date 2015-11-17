#include <stdio.h>

int foo(int a, int b, int c){

  return a+b+c;

}

int goo(int a, int b, int c){

  return a+b;

}

int my_print(int a, int b){
  printf("Inside my_print \n");
  return 420;
}

void bar(int (*my_another_func_pointer) (int, int)){
  printf("I am inside bar \n");
  int p = my_another_func_pointer(20, 30);  
  printf("p is %d \n",p);
}

int main(){

int (*my_pointer) (int, int, int);

my_pointer = &foo;
int p = my_pointer(5,10,15);
printf("%d \n",p);

my_pointer = &goo;
p = my_pointer(5,10,15);
printf("%d \n",p);

//passing address of func as argument is called callback
bar(&my_print);
return 0;
}
