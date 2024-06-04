
#include <iostream>
using namespace std;

void reverseString(string str, int size){
    if(size == 0){
        
        return;
    }
    if(size > 0){
    int newSize = size -1;
    cout << str[newSize];
    
    return reverseString(str, newSize);
        
    }
    
    
}
int main()
{
    string str = "anurag";
    int size = str.size();
    cout << size << endl;
    reverseString(str, size );
    
}
