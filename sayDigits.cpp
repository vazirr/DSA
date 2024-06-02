

#include <iostream>
using namespace std;

#define PI 3.14
#define min(a,b) (((a) < (b)) ? a : b )

void sayDigit(int n, string arr[]){
    //base case
    if(n == 0){
        
    return;
}

//processing
int digit = n %10;
n = n /10;

sayDigit(n, arr);

cout << arr[digit] << " ";

//recursive call


}

int main()
{
  string arr[10] = {"zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
 int n;
 cin >> n;
 cout << endl;
 
sayDigit(n, arr);
 cout << endl;
 
}
