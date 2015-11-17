//Rotate 2D array using another temp array

#include <stdio.h>

void rotate(int src[][4], int dest[][4], int N){

  for(int i=0;i<N;i++)
      for(int j=0;j<N;j++)
         dest[j][N-1-i] = src[i][j];

}

void print(int a[][4], int N){

  for(int i=0; i<N; i++){
    for(int j=0;j<N;j++) {
       printf("%d ", a[i][j]);
    }
   printf("\n");
  }
}

int main(){

int a[4][4] = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16}};
int d[4][4];

print(a, 4);
printf("\n\n\n\n");
rotate(a, d, 4);
print(d,4);

return 0;
}
