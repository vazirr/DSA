//page no: 21 ---------------------------------------------------------------------------------------------------------------

class Solution 
{
    public:
    bool knows(vector<vector<int> >& M, int a, int b, int n){
        if(M[a][b] == 1){
            return true;
            
        }else{
            return false;
            
        }
        
    }
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
       stack<int> s;
       
       //step 1 : push all element in stack
       for(int i = 0; i<n; i++){
           s.push(i);
       }
       
       //step 2: compare 2 elements 
       while(s.size() > 1){
           int a = s.top();
           s.pop();
           
           int b = s.top();
           s.pop();
           if(knows(M,a,b,n)){
               s.push(b);
           }else{
               s.push(a);
               
           }
       
    }
    
    int candidate = s.top();
    
    //step 3 : single element in stack is potential element
    //verify karlo
    bool rowCheck = true;
        for (int i = 0; i < n; i++) {
            if (M[candidate][i] != 0) {
                rowCheck = false;
                break;
            }
        }
        
        bool colCheck = true;
        for (int i = 0; i < n; i++) {
            if (i != candidate && M[i][candidate] != 1) {
                colCheck = false;
                break;
            }
        }
        
        if (rowCheck && colCheck) {
            return candidate;
        }
        return -1;
    }
};
