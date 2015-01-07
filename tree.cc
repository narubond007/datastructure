#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  struct node *left;
  struct node *right;
  int data;
}NODE;

//Defining the root of the tree
NODE *root = NULL;

//Node will be initialized with the following values
int init[10]={127,70,90,137,2,31,63,126,15,99};


NODE* insert(NODE **temp, int data){

    if(*temp == NULL){
      NODE *new_node = (NODE *)malloc(sizeof(NODE));
      new_node->data = data;
      new_node->left = new_node->right = NULL;
      return new_node;
    }

    if(data < (*temp)->data){
      (*temp)->left = insert(&(*temp)->left, data);
    }
    if(data > (*temp)->data) {
      (*temp)->right = insert(&(*temp)->right, data);
    }
 
    return *temp;
}


//print using preorder, inorder, postorder
void printInorder(){


}

//functions to be implemented are insert, delete, findAndInsert, etc, print
int main(){

  for(int i=0;i<10;i++){
   printf("%d  \n",i);
   root = insert(&root, init[i]);
  }
  printf("Data is %d \n",root->data);
  //printLL();
   
  /* int option=0;
   while(true){
    printf("1. Print, 2. InsertAter, 3. InsertBefore, 4. Del, 5. PrintReverse, 6.ReverseLL \n");
    scanf("%d",&option);

    switch(option){

    case 1:
     printLL();
     break;
    case 2:
     printf("Enter element to be searched, new data to be inserted ");
     scanf("%d %d",&elementToBeSearched, &newData);
     insertAfter(elementToBeSearched, newData);
     break;
    case 3:
     printf("Enter element to be searched, new data to be inserted ");
     scanf("%d %d",&elementToBeSearched, &newData);
     insertBefore(elementToBeSearched, newData);
     break;
    case 4:
     printf("Enter element to be deleted: ");
     scanf("%d", &dataToBeDeleted);
     del(dataToBeDeleted);
     break;     
    case 5:
     printReverseLL(head);
     printf("\n");
     break;
    case 6:
     reverseLL();
     break;
    default:
     printf("Wrong option selected \n");

    }
   } */
    
  return 0;
} 
