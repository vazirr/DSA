
//https://www.geeksforgeeks.org/problems/maximum-sum-of-non-adjacent-nodes/1
//page no 69

class Solution{
  public:
    //Function to return the maximum sum of non-adjacent nodes.
    
    pair<int,int> solve(Node* root){
        //base case 
        if(root == NULL){
            pair<int,int> p = make_pair(0,0);
            return p;
        }
        
        
        pair<int,int> leftAns = solve(root->left);
        pair<int,int> rightAns = solve(root->right);
        
        pair<int,int> result;
        
        result.first = root->data + leftAns.second + rightAns.second;
        result.second = max(leftAns.first, leftAns.second) + max(rightAns.second, rightAns.first);
    
        return result;
    }
    int getMaxSum(Node *root) 
    {
        pair<int,int> ans = solve(root);
        return max(ans.first,ans.second);
    }
};
