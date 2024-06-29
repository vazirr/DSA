
//page 27 , 28 ---------------------------------------------------------------------------------------------------------------------

include <stack>
class SpecialStack {
    stack<int> s;
    int mini;

    public:
        
    void push(int data) {
        //for first element
         if(s.empty()){
             s.push(data);
             mini = data;
         }else{
             if(data < mini){
                 int val = 2*data - mini;
                 s.push(val);
                 mini = data;
             }else{
                 s.push(data);

             }
         }
    }

    void pop() {
        // Implement the pop() function.
        if(s.empty()){
            return -1;
        }
        int curr = s.top();
        if(curr > mini){
            return curr;    
        }else{
            int prevMin = mini;
            int val = 2*mini - curr;
            mini = val;
            return prevMin;
        }
    }

    int top() {

            if(s.empty()){
                return -1;
            }
            int curr = s.top();
            if(curr < mini){
                return mini;
            }else{
                return curr;
            }
        // Implement the top() function.
    }

    int getMin() {
        if(s.empty()){
            return -1;
        }
        return mini;

        // Implement the getMin() function.
    }  
};
