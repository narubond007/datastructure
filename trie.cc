/* Trie data structure, with insert and find operation */

#include <iostream>
#include <string.h>
#include <stdint.h>
#include <fstream>
#include <string>

class Node{

public:
  char data;
  Node *children[128];
  uint32_t count;
  Node() {
   //initialize the children node to NULL;
   for(int i=0;i<128;i++){
      children[i] = NULL;
   }
   count = 0;
  }
};


//Insert a node into the Trie structure
void insert (Node **root, const char *input){

    Node *temp = *root;
    int i=0;
 
    while(i < strlen(input)){

       if(temp->children[input[i]] == NULL){
          Node *newNode = new Node();
          newNode->data = input[i];
          temp->children[input[i]] = newNode;
        }

       temp->children[input[i]]->count++;
       temp = temp->children[input[i]];
       i++;    
    }

}

//Find operation
bool find (Node *root, const char *search){

  Node *temp = root;
  int i=0;

  //Keep going till the node orthe data belonging to the node is the one you are looking for
    while(i < strlen(search)){
       if(temp->children[search[i]] == NULL) return false;
       if(temp->children[search[i]]->data != search[i]) return false;
       std::cout<<temp->children[search[i]]->data <<"("<<temp->children[search[i]]->count<<")"<<" ";
       temp = temp->children[search[i]];
       i++;
    }

  return true;
}

int main(){

Node *root = new Node();
root->data = 0;

//insert(&root, "andy");
//insert(&root, "barca");
//insert(&root, "andyiamo");
//insert(&root, "arabic");

//Insert the entire dictionary, read from file
std::cout<<"Inserting the entire dictionary"<<std::endl;
std::ifstream file("dictionary");
std::string str; 
while (std::getline(file, str))
{
   insert(&root, str.c_str());
}
std::cout<<"completed inserting the entire dictionary"<<std::endl;


//Find operation
std::string findStr;
while(true){
std::cout << "Enter string to find: "<<std::endl;
std::cin>>findStr;
if(find(root, findStr.c_str())) {
  std::cout<<"Found string"<<std::endl;
}
}

return 0;
}
