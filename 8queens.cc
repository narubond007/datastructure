#include <stdio.h>
#include <stdlib.h>

#define BOARD 8

/* Init the board to 0. */
static int board[BOARD][BOARD] = {0};
static int r[BOARD] = {-1}; 

/* Checker func to see if you can place the queen there. */
bool checker(int row, int index){

bool ret=true;

/* Check if array index out of bounds. */
if((row >= BOARD) || (index >= BOARD) || (row<0) || (index<0)){
  return false;
}

/* check if by chance already placed in that square...safety purpose..*/
if(board[row][index] == 1)return false;

//go north all the way i.e same index, but row will change
for(int i=row-1; i>=0; i--){
 if(board[i][index] == 1) return false;
}

//go south all the way i.e same index, but row will change
for(int i=row+1; i<BOARD; i++){
 if(board[i][index] == 1) return false;
}

//go east all the way i.e same row, but index changes
for(int i=index+1; i<BOARD; i++){
 if(board[row][i] == 1) return false;
}

//go west all the way i.e same row, but index changes
for(int i=index-1; i>=0; i--){
 if(board[row][i] == 1) return false;
}

//go north-east all the way i.e upper right diagonal i.e row decreases, index increases 
for(int i=index+1, j=row-1;  i<BOARD && j>=0 ; i++,j--)
{ 
   if(board[j][i] == 1) return false;
}
//go north-west all the way i.e upper left diagonal i.e row decreases, index decreases
for(int i=index-1, j=row-1;  i>=0 && j>=0 ; i--,j--)
{
   if(board[j][i] == 1) return false;
}

//go south-east all the way  i.e lower right diagonal i.e row increases, index increases
for(int i=index+1, j=row+1;  i<BOARD && j<BOARD ; i++,j++)
{
   if(board[j][i] == 1) return false;
}

//go south-west all the way i.e lower left diagonal i.e row increases, index decreases
for(int i=index-1, j=row+1;  i>=0 && j<BOARD ; i--,j++)
{
   if(board[j][i] == 1) return false;
}

return ret;
}

void printThis()
{
 printf("\n");
  for(int i=0;i<BOARD;i++){
    for(int j=0;j<BOARD;j++){
      if(board[i][j]==1) printf(" Q ");
      else printf(" . ");
   } 
  printf("\n");
 }
}

int scan(int row){

  static int count=1;
  int i=0;
  for(i=r[row]+1; i<BOARD; i++){
      bool ret=checker(row,i);
      if(ret == true) {
          board[row][i] = 1;
          r[row]=i;
          if(row == BOARD-1) { 
                  printf("\n Match# %d",count); 
                  count++; 
                  printThis(); 
                  board[row][r[row]]=0; 
                  /* This is the case where all queens are placed correctly. */ 
                  return row; 
           }  else 
                 return row+1;
      }
  }  

  if((row==0) && (i == BOARD)) exit(-1);

  r[row]=-1;
  board[row-1][r[row-1]]=0;
  return row-1;

}


int main(int argc, char **argv){

/* int.. place queen at 0,0. And start scanning from the next row..i.e r#1.. */
board[0][0]=1;
r[0]=0;
int nextRow=1;

while(1){
    nextRow = scan(nextRow);
} //end of while

return 0;
}
