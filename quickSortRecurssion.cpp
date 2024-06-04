/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;

int partition(int* arr, int s, int e){
    int pivot = arr[s];
    int count = 0;
    
    for(int i = s+1; i <= e; i++){
        if(arr[i]<=pivot){
            count++;
        }
        
    }
    //place pivot place at right index(sahi index pivot ka)
    int pivotIndex = s + count;
    swap(arr[pivotIndex], arr[s]);
    
    
    int i = s, j = e;
    
    while(i < pivotIndex && j>pivotIndex){
        
        
        while(arr[s] <= pivot){
                i++;
        }
        while(arr[j] > pivot){
            j--;
        }
        if(i < pivotIndex && j>pivotIndex){
            swap(arr[i++],arr[j--]);
        }
    }
    
    return pivotIndex;
}

void quickSort(int* arr, int s, int e){
    
    if(s>=e){
        return;
    }
    //partition karle
    int p =partition(arr, s, e);
    
    //left part sort karenge
    quickSort(arr, s, p - 1);
    //right part sort karenge
    quickSort(arr, p + 1, e);
    
    
    
    
}
int main()
{
    
    int arr[5] = {11,5,1,6,9};
    int n = 5;
    
    quickSort(arr, 0, n-1);
    
   for(int i=0; i<n; i++){
       cout<<arr[i] << " ";
   }
   cout << endl;
    
}
