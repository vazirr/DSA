

//page 89 90
/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;
class heap {
    public :
    int arr[100];
    int size;
    
    heap(){
        arr[0] = -1;
        size = 0;
    }
    
    
    void insert(int val){
        size += 1;
        int index = size;
        arr[index] = val;
        
        while(index > 1){
            int parent = index / 2;
            if(arr[parent] < arr[index]){
                swap(arr[parent], arr[index]);
                index = parent;
            }else{
                return;
            }
        }
        
    }
            
      void print(){
          for(int i = 1; i <= size; i++){
              cout << arr[i] << " ";
          }cout << endl;
      }  
      
      void deletefromHeap(){
          if(size == 0){
              cout << "Heap is empty" << endl;
              return;
          }else{
              //put last element into first position
              arr[1] = arr[size];
              //remove last element
              size--;
              
              
              //take root node to its correct position
              int i = 1;
              while(i < size){
                  int leftIndex = 2*i;
                  int rightIndex = 2*i + 1;
                  
                  if(leftIndex < size && arr[i] < arr[leftIndex]){
                      swap(arr[leftIndex], arr[i]);
                      i = leftIndex;
                  }else if(rightIndex < size && arr[i] < arr[rightIndex] ){
                      swap(arr[i], arr[rightIndex]);
                      i = rightIndex;
                  }else{
                      return;
                  }
              }
          }
          
      }
      
          
      
        
    };
      void heapify(int arr[], int n, int i){
          int largest= i;
          int left = 2*i;
          int right = 2*i + 1;
          
          if(left < n && arr[largest] < arr[left]){
    
          
          }    largest = left;
          
          if(right < n && arr[largest] < arr[right]){
              
              largest = right;
          }
          if(largest != i){
              swap(arr[la
              hrgest], arr[i]);eapify(arr, n , largest);
          }
      }
int main()
{
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();
    h.deletefromHeap();
    h.print();
    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;
    for(int i = n/2; i > 0; i--){
        heapify(arr,n,i);        
    }
    
    cout << "printing array now : " << endl;
    for (int i = 1; i <= n; i++){
        cout << arr[i] << " ";
    }cout << endl;
    
}
