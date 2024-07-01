
//page 34 --------------------------------------------------------------------------------------------

class Solution
{
    public:
    
    // Function to reverse first k elements of a queue.
    queue<int> modifyQueue(queue<int> q, int k) {
       stack<int> s;
        //pop first k element from queue and put it in stack
        for(int i = 0; i<k;i++){
            int ans = q.front();
            s.push(ans);
            q.pop();
        }
        
        while(!s.empty()){
            int ans = s.top();
            q.push(ans);
            s.pop();
        }
        
        for(int i = 0; i< q.size() - k; i++){
            int ans = q.front();
            q.push(ans);
            q.pop();
        }
        
        return q;
    }
};
