#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main()
    {
    struct tm *Sys_T = NULL;
    time_t Tval = 0;
    Tval = time(NULL);
    Sys_T = localtime(&Tval);

    int Day=Sys_T->tm_mday;
    int Month=Sys_T->tm_mon+1;
    int Year=1900 + Sys_T->tm_year;
    int Hour=Sys_T->tm_hour;
    int Min=Sys_T->tm_min;
    int Sec=Sys_T->tm_sec;


    switch(Month){
     case 1: printf("JAN,"); break;
     case 2: printf("FEB,"); break;
     case 3: printf("MAR,"); break;
     case 4: printf("APR,"); break;
     case 5: printf("MAY,"); break;
     case 6: printf("JUN,"); break;
     case 7: printf("JUL,"); break;
     case 8: printf("AUG,"); break;
     case 9: printf("SEP,"); break;
     case 10: printf("OCT,"); break;
     case 11: printf("NOV,"); break;
     case 12: printf("DEC,"); break;
   }   

    printf(" %d", Day);
    printf(" %d,", Year);
   
    printf(" %d:", Hour);
    printf("%d:", Min);
    printf("%d", Sec);
    printf("\n");

return 0;
}
