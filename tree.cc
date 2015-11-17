/* All tree operations:
Insert  done
Search  done

InOrder done
PreOrder done
PostOrder done

BFS done

Delete  done

Print tree at levels  done

find depth of tree
find if tree is BST
find if tree is balanced

common ancestor

Given inorder/pre-order construct tree

Given sorted array, construct tree with minimum height

Given tree and subtree, see if subtree is present in tree
*/


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
int init[18]={127,70,90,137,2,63,31,99,129, 77, 135, 134, 103, 101, 104, 25, 24, 27 };

int find_successor(NODE **node){

   NODE *parent = *node;
   NODE *temp = (*node)->right;
 
   //Case 1: The right node has left children, delete the right node, return the data belonging to right node.
   if(temp->left == NULL) {
     int tmp = temp->data;
     parent->right = temp->right;
      printf("Find successor: case where right node has no left children \n");
      delete temp;
      temp = NULL;
      return tmp;
    }

   //Case 2: Find the left most node in the tree.
   while(temp->left != NULL) {
     parent = temp;
     temp = temp->left;
   }

   //If the left-most node has no children, delete the node and return the data belonging to this node.
    if((temp->left == NULL) && (temp->right == NULL)) {
       printf("Find successor: case where the left most node has no children \n");
       int tmp = temp->data;
       delete temp;
       temp = NULL;
       return tmp;
    } else if(temp->right) {
       printf("Find successor: case where the left most node has a right subtree \n");
       parent->left = temp->right;
       int tmp = temp->data;
       delete temp;
       temp = NULL;
       return tmp;
    }
   
  printf("ERROR: cannot return from here \n");
  return -1;
}


void del(int number){

  //find the number
  NODE *node = root;
  bool isLeft = true;
  NODE *parent = root;
  
  if(!root) {
    printf("root is null \n");
    return;
  }
  if((node->data == number) && (node->left == NULL) && (node->right==NULL)){
    printf("Deleted root. This was the only element \n");
    delete node;
    node = NULL;
    return;
  }
  
  //Find the node
  while ((node->data != number) && (node)) {
    parent = node;
    if(number < parent->data){
        node = node->left;
        isLeft = true;
     } else {
         node = node->right;
         isLeft = false;
     }
   }

    if(!node) {
       printf("Node is not found \n");
       return;
     }

    //Now, node is found, you have its parent, and you also know if the node is left or right child of parent
    
     //Case 1: Node has no children
     if((node->right == NULL) && (node->left == NULL)){
        printf("Deleted node has no children \n");
        delete node;
        node = NULL;
        return;
     }

     //Case 2: Node has left tree only, but right tree is null
     //Case 3: Node has right tree only, but left tree is null
     if((node->right == NULL) && (isLeft)){
          printf("Deleted node is left child and has no right children, but has left children \n");
          parent->left = node->left;
          delete node;
          node = NULL;
          return;
      } else if ((node->right == NULL) && (!isLeft)) {
          printf("Deleted node is right child and has no right children, but has left children \n");
          parent->right = node->left;
          delete node;
          node = NULL;
          return;
      } else if ((node->left == NULL) && (isLeft)){
          printf("Deleted node is left child and has no left children, but has right children \n");
          parent->left = node->right;
          delete node;
          node = NULL;
          return;
      } else if ((node->left == NULL) && (!isLeft)) {
          printf("Deleted node is right child and has no left children, but has right children \n");
          parent->right = node->right;
          delete node;
          node = NULL;
          return;
      }
    
     //Fancy case is when node has left and right children
     node->data= find_successor(&node);
  
} 
      



//Remember, search can be done by while loop as well, i.e  non recursive method
void search(NODE *node, int element){

   if(node->data == element) {
       printf("Found \n");
       return;
    }
   if(node == NULL) return;

   if((node->right) && (element > node->data))  search(node->right, element);
   if((node->left) && (element < node->data))  search(node->left, element);

}
void BFS_by_level(NODE *node) {

std::queue<NODE *> my_queue;

if(!node){
   printf("Tree is empty \n");
   return;
}

my_queue.push(node);
my_queue.push(NULL);

while(!my_queue.empty()){
   NODE *temp = my_queue.front();
   my_queue.pop();
   if(!temp){
      printf("\n");
      //Only insert NULL element if the queue is non empty. If the queue is empty, then this is the time to break off of the loop.
      if(!my_queue.empty()) my_queue.push(NULL);
   } else {
     printf("%d ",temp->data);
     if(temp->left) my_queue.push(temp->left);
     if(temp->right) my_queue.push(temp->right);
   }
}
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

  for(int i=0;i<18;i++){
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
  printf("\n");

  BFS_by_level(root);
  printf("\n");

  printInorder(root);
  printf("\n");
  del(2);
  BFS_by_level(root);
  printf("\n");

  printInorder(root);
  printf("\n");
  return 0;
} 
