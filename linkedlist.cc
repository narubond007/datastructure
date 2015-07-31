#include <stdio.h>
#include <stdlib.h>

typedef struct LL{
  struct LL *next;
  int data;
}LL;

//Defining the head of the linked list
LL *head = NULL;

//LL will be initialized with the following values
int init[10]={127,70,90,137,2,31,63,126,15,99};

void printLL(){
  //check if head is null;
  if(!head){
    printf("Linked list is NULL \n");
    return;
  }

  LL *temp = head;
  do{
   printf("%d ",temp->data);
   temp = temp->next;
  } while(temp != NULL);

  printf("\n");
}

//reverse LL using recursion
void reverseLLrecursion(LL *node){

  if(node==NULL) return;
  reverseLLrecursion(node->next);
  if(node->next == NULL) head = node;
  else {
       node->next->next = node;
       node->next = NULL;
  }
}



void reverseLL(){

  /* In this iterative method, we scan through the LL once. Take out each element and append it behind the head.
     Thus, slowly, the head becomes the tail. */
  LL *temp= head;
  while(temp->next != NULL){
   LL *mid_element = temp->next;
   temp->next = mid_element->next;
   mid_element->next = head;
   head = mid_element;
  }
  printf("Reversed LL successfully \n");
}

void printReverseLL(LL *temp){

  if(temp == NULL){
   return;
  }
  printReverseLL(temp->next);
  printf("%d ",temp->data);
}


void insertAfter(int data, int newElement){

LL *temp= head;
//Find the element
while(temp){
   if(temp->data == data){
    break;
   } else {
    temp = temp->next;
   }
}

if(!temp){
  printf("Didnt find the element %d in the LL. \n",data);
  return;
}

LL *node = (LL *)malloc(sizeof(LL));
node->data = newElement;
node->next = temp->next;
temp->next=node;
printf("Inserted element successfully AFTER %d\n",data);

}   


void insertBefore(int data, int newElement){

LL *temp= head;

//Inserting before the head condition
if(temp->data == data){
  LL *node= (LL *)malloc(sizeof(LL));
  node->data = newElement;
  node->next = head;
  head = node;
  printf("Inserted element at head. \n");
  return;
}

//Find the element
while(temp->next != NULL){
   if((temp->next)->data == data){
    break;
   } else {
    temp = temp->next;
   }
}

if(temp->next == NULL){
  printf("Didnt find the element %d in the LL. \n",data);
  return;
}

LL *node = (LL *)malloc(sizeof(LL));
node->data = newElement;
node->next = temp->next;
temp->next=node;
printf("Inserted element successfully BEFORE %d \n",data);

}


void del(int data){

//Delete the head
if(head->data == data){
  LL *node= head;
  head = head->next;
  free(node);
  printf("Deleted element at head. \n");
  return;
}

LL *temp=head;
//Find the element
while(temp->next != NULL){
   if((temp->next)->data == data){
    break;
   } else {
    temp = temp->next;
   }
}

if(temp->next == NULL){
  printf("Didnt find the element %d in the LL. \n",data);
  return;
}

LL *node = temp->next;
temp->next = node->next;
free(node);
printf("Deleted element %d \n",data);

}

void insert(int data){

  //create the node
  LL *temp = (LL *)malloc(sizeof(LL));
  temp->data = data;

  if(!head){
   temp->next = NULL;
   head = temp;
  } else {
   temp->next = head;
   head = temp;
  }

}


//functions to be implemented are insert, delete, findAndInsert, etc, print
int main(){

  int elementToBeSearched, newData, dataToBeDeleted;
  for(int i=0;i<10;i++){
   insert(init[i]);
  }
  printLL();
   
   int option=0;
   while(true){
    printf("1. Print, 2. InsertAter, 3. InsertBefore, 4. Del, 5. PrintReverse, 6.ReverseLL, 7. ReverseLLRecursion \n");
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
    case 7:
     reverseLLrecursion(head);
     break;
    default:
     printf("Wrong option selected \n");

    }
   }
    
  return 0;
} 
