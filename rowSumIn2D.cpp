

#include <iostream>
using namespace std;

//to print row wise sum
void printSum(int arr[][4], int row, int col){
    cout<<"Printig sum ->"<<endl;
      for(int row = 0; row<3;row++){
          int sum =0;
        for(int col=0; col<4; col++){
            sum+=arr[row][col];
        }
        cout<<sum<<" ";
    }
    cout<<endl;
    
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
    
    printSum(arr, 3,4);
   
}
