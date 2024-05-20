

#include <iostream>
#include <climits>
using namespace std;


int largestRowSum(int arr[][4], int row, int col){
    int maxi = INT_MIN;
    int rowIndex = -1;
    for(int row = 0; row<3;row++){
          int sum =0;
        for(int col=0; col<4; col++){
            sum+=arr[row][col];
        }
       if(sum>maxi){
           maxi = sum;
           rowIndex = row;
       }
    }
    cout<<"the maximum sum is : "<<maxi<<endl;
    return rowIndex;
    
    
}
int main()
{
    int arr[3][4];
    cout<<"Enter the elements: "<<endl;
    for(int row = 0; row<3;row++){
        for(int col=0; col<4; col++){
            cin >> arr[row][col];
        }
    }
    
    cout << "The elements are: "<<endl;
      for(int row = 0; row<3;row++){
        for(int col=0; col<4; col++){
            cout << arr[row][col]<<" ";
        }
        cout<<endl;
    }
    
   int ansIndex = largestRowSum(arr, 3, 4);
   cout << "The maximum row sum index is :" << ansIndex <<endl;
   
}
