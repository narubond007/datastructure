#include <iostream>
#include <map>

using namespace std;

//Given a number, you need to find if sum of two elements from the array yields the given number
int a[] = {8,5,3,16,7,9};

int main(){

int NUM = 25;
map<int, int> myMap;

//populate the map with array, Key is the array elements, value is the indice
for(int i=0; i<6; i++){
 myMap[a[i]]=i;
}

//iterate the map, find if NUM - iterator = element in the map
auto it = myMap.begin();

while(it != myMap.end()){
   auto itTemp = myMap.find(NUM - it->first);
   if(itTemp != myMap.end()) {
      cout << "Elements giving NUM "<<NUM<<" are "<< it->first << " " << itTemp->first << endl;
      cout << "Indices of those elements in the array are "<< it->second << " " << itTemp->second << endl;
      break;
   }
   it++;
}

return 0;
}



