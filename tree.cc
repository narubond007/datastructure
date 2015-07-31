#include <stdio.h>
#include <stdlib.h>
#include <queue>

typedef struct node{
  struct node *left;
  struct node *right;
  int data;
}NODE;

//Defining the root of the tree
NODE *root = NULL;

//Node will be initialized with the following values
int init[10]={127,70,90,137,2,63,31,99,129, 77 };


int findmin(NODE *node){

  int val;
  while(!node){
   val = node->data;
   node = node->left;
  }

 return val;

}
void remove(int data, NODE *parent, NODE *node){

   if(data == node->data){

        //If the node has no left tree, then dictly link with parent
        if((node->left == NULL) && (node->right)) {
          
             if(parent->data < node->data){
                 //shift right
                 parent->right = node->right;
                 free(node);
                 return;
             } else if (parent->data > node->data) {
                 //shift left
                 parent->left = node->left;
                 free(node);
                 return;
             }
        } else if ((node->right == NULL) && (node->left)) {

           if(parent->data < node->data){
                 //shift right
                 parent->right = node->right;
                 free(node);
                 return;
             } else if (parent->data > node->data) {
                 //shift left
                 parent->left = node->left;
                 free(node);
                 return;
             }
        } else if ((node->right == NULL) && (node->left == NULL)){
                if(parent->data > node->data) parent->left = NULL;
                else parent->right = NULL;
                free(node);
                return;
        } else if ((node->right) && (node->left)) {


            //Find the minimu value in the rightmost tree
            int value = findmin(node->right);
            node->data = value;
            remove(value, node->right, node->right);
        }
     } else if( data > node->data) {

          remove(data, node, node->right);
     } else if( data < node->data) {

          remove(data, node, node->left);
     }
}

void search(NODE *node, int element){

   if(node->data == element) {
       printf("Found \n");
       return;
    }
   if(node == NULL) return;

   if((node->right) && (element > node->data))  search(node->right, element);
   if((node->left) && (element < node->data))  search(node->left, element);

}

void BFS(NODE *node){

  std::queue<NODE *> my_queue;
 
  if(!node){
    printf("Tree is empty\n");
    return;
  }
 
  my_queue.push(node);

  while(!my_queue.empty()){
   
     //print the element
     NODE *temp = my_queue.front();
     printf("%d ",temp->data);
     if(temp->left) my_queue.push(temp->left);
     if(temp->right) my_queue.push(temp->right);
     my_queue.pop();
   }
}


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
void printInorder(NODE *node){

  if(!node) return;
  printInorder(node->left);
  printf("%d  ",node->data);
  printInorder(node->right);

}

//print using preorder
void printPreorder(NODE *node){

  if(!node) return;
  printf("%d  ",node->data);
  printPreorder(node->left);
  printPreorder(node->right);

}

//print using preorder, inorder, postorder
void printPostorder(NODE *node){

  if(!node) return;
  printPostorder(node->left);
  printPostorder(node->right);
  printf("%d  ",node->data);
}



//functions to be implemented are insert, delete, findAndInsert, etc, print
int main(){

  for(int i=0;i<10;i++){
   root = insert(&root, init[i]);
  }
  printf("Data is %d \n",root->data);
   
  printf("Inorder traversal \n");
  printInorder(root); 
  printf("\n");

  printf("Preorder traversal \n");
  printPreorder(root);
  printf("\n");

  printf("Postorder traversal \n");
  printPostorder(root);
  printf("\n");

  printf("BFS \n");
  BFS(root);
  printf("\n");

  printf("Search \n");
  search(root, 99);

  printf("Delete \n");
  remove(127, root, root);
  BFS(root);
  printf("\n");
  return 0;
} 
