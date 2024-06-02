

#include <iostream>
using namespace std;

#define PI 3.14
#define min(a,b) (((a) < (b)) ? a : b )
bool isSorted(int arr[], int size){
    if(size == 0 || size == 1){
        return true;
    }
    if(arr[0] > arr[1]){
        return false;
    }
    else{
        bool remainingPart = isSorted( arr + 1, size - 1);
        return remainingPart;
    }
}
int main()
{
 
 int arr[5] = {2, 4, 6, 10, 9};
 int size = 5;
 
 bool ans = isSorted(arr, size);
 if(ans)
 cout << "Sorted"<<endl;
 else cout << "Unsorted" << endl;
 
}
