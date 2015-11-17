/* Remove duplicate element from linkedlist (uses hashmap)
   Reverses the linked list using recursion
*/

#include <iostream>
#include <map>
#include <stdio.h>

using namespace std;

typedef struct node{
int data;
struct node *next;
}NODE;

NODE *head = NULL;
NODE *tail = NULL;

void insert(int data){

   NODE *temp = new NODE();
   temp->data = data;
   temp->next = NULL;

   if(head == NULL){
     head = tail = temp;
   } else {
     tail->next = temp;
     tail = temp;
   }
}
  
void print(NODE *node){
    while(node) {
       cout << node->data << " ";
       node = node->next;
    }
    cout << endl;
} 

void remove_dup_hash(){

    static map<int, int> frequency;

    if(!head) {
      printf("LL is empty \n");
      return;
    } else if(! head->next) {
      printf("LL has only one element \n");
      return;
    }

    NODE *temp = head;
    while(temp){
       frequency[temp->data]++;
       if(frequency[temp->data] > 1) {
           //delete temp
           
            //temp can be last node
            if(!temp->next) {
                cout << "Deleting last node"<<temp->data<<endl;
                delete temp;
                temp = NULL;
                break;
            } else {
                cout << "Deleting "<<temp->data<<endl;
                temp->data = temp->next->data;
                NODE *del = temp->next;
                temp->next = temp->next->next;
                delete del;
                del = NULL;
            }
        }
        else {
           temp = temp->next;
         }
     }
       

}

void reverse(NODE *temp, NODE *prev){
    if(temp->next == NULL){
         head = temp;
         temp->next = prev;
         return;
    }
    reverse(temp->next, temp);
    temp->next = prev;
}

int main(){
   
    insert(3);
    insert(4);
    insert(5);
    insert(6);
    insert(7);
    insert(5);
    insert(6);
    insert(6);

    print(head);

    //remove_dup_hash();
    //print(head);

      reverse(head, NULL);
      print(head);
}
