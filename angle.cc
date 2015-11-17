#include <stdio.h>

int main(){

int hrs, mins;
hrs = 3;
mins = 15;
int angle = 0;

//find the ref of hr hand wrt 12 o clock position. hr moves 360 deg in 12*60 mins.
//So, find how much it has moved from 12 o clock position in x hrs, y mins
int hrs_ref = (hrs*60 + mins)/2;
//find the ref of min hand wrt 12 o clock position. min moves 360 deg in 60 mins.
//So, find how much it has moved from 12 o clock position in y mins.
int mins_ref = 6*mins;

//diff of the hr_hand_ref and min_hand_ref is the angle between hr hand and min hand
if(hrs_ref > mins_ref) 
   angle = (hrs_ref - mins_ref)%360;
else if (mins_ref > hrs_ref)
   angle = (mins_ref - hrs_ref) % 360;
else if (mins_ref == hrs_ref)
   angle = 0;
else
   printf("Unknown");


printf("Angle for %d hrs:%d mins  is %d",hrs, mins,angle);

return 0;
}
