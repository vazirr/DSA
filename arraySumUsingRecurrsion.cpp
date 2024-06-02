
#include <iostream>
using namespace std;


int arrSum(int arr[], int size){
    if(size == 0){
        return 0;
    }
    if(size == 1){
        return arr[0];
    }
    int ans =  arr[0] + arrSum(arr + 1, size - 1);
    return ans;
}
int main()
{
 
 int arr[5] = {2, 4, 6, 8, 9};
 int size = 5;
 
 
 int sum = arrSum(arr, size);
 cout <<" The sum of an array " << sum << endl;
 
}
