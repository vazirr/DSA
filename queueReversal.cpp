//page 33

class Solution
{
    public:
    queue<int> rev(queue<int> q)
    {
        stack<int> s;
        while(!q.empty()){
            int ans = q.front();
            q.pop();
            s.push(ans);
            
        }
        
        while(!s.empty()){
            int ans = s.top();
            q.push(ans);
            s.pop();
        }
        return q;
    }
};
