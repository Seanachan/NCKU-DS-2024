#include<iostream>
#include<vector>
using namespace std;
void swap(int &a, int &b){
  int tmp = a;
  a = b;
  b = tmp;
}
void delKey(vector<int> &v){

}
void insertMinHeap(vector<int> &v,int val){
  //min Heap Tree
  int idx = v.size();
  v.push_back(val); 
  while (idx > 1 && v[idx] < v[idx / 2]) {
    swap(v[idx], v[idx / 2]);
    idx = idx / 2;
  }
}

void insertMaxHeap(vector<int> &v,int val){
  //max Heap Tree
  int idx = v.size();
  v.push_back(val); 
  while (idx > 1 && v[idx] > v[idx / 2]) {
    swap(v[idx], v[idx / 2]);
    idx = idx / 2;
  }
}
int main(){
  vector<int> maxHeap;
  maxHeap.push_back(0);//1-index
  insertMaxHeap(maxHeap,7); insertMaxHeap(maxHeap,16); insertMaxHeap(maxHeap,49); 
  insertMaxHeap(maxHeap,2); insertMaxHeap(maxHeap,5); insertMaxHeap(maxHeap,31); 
  insertMaxHeap(maxHeap,6); insertMaxHeap(maxHeap,2); insertMaxHeap(maxHeap,44); 

  for(int i =0;i<maxHeap.size();i++) {
    printf("%d ",maxHeap[i]); 
  }
  printf("\n"); 
  vector<int> minHeap;
  minHeap.push_back(0);                     //
  insertMinHeap(minHeap,7); insertMinHeap(minHeap,16); insertMinHeap(minHeap,49); 
  insertMinHeap(minHeap,2); insertMinHeap(minHeap,5); insertMinHeap(minHeap,31); 
  insertMinHeap(minHeap,6); insertMinHeap(minHeap,2); insertMinHeap(minHeap,44); 

  for(int i =0;i<minHeap.size();i++) {
    printf("%d ",minHeap[i]); 
  }


  return 0;
}
