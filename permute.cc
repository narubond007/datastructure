#include <stdio.h>
#include <string.h>
#include <map>


void permute(int start, char *input) {

    if (start == strlen(input)) {
        printf("%s \n",input);
        return;
    }

    for (int i = start; i < strlen(input); i++) {

        //swap(input[i], input[start]);
        char tmp = input[i];
        input[i] = input[start];
        input[start] = tmp;

        permute(start + 1, input);

        //Perhaps, you dont need this. You need this only to retain the actual string.
        //swap(input[i],input[start]);
        //tmp = input[i];
        //input[i] = input[start];
        //input[start] = tmp;
    }
}

int main(){

char input[] = "abc";

permute(0, input);
printf("--- actual string is %s \n",input);
return 0;
}
