
//https://www.geeksforgeeks.org/problems/right-view-of-binary-tree/1

//page no 61

class Solution
{
    public:
    //Function to return list containing elements of right view of binary tree.
    void solve(Node* root, vector<int> &ans, int level){
        
        if(root ==  NULL){
            return;
        }
        
        //if we enetered in new level
        
        if(level == ans.size()){
            ans.push_back(root->data);
        }
        
        solve(root->right,ans,level+1);
        solve(root->left, ans, level+1);
    }
    
    vector<int> rightView(Node *root)
    {
       // Your Code here
       vector<int> ans;
       solve(root,ans,0);
       return ans;
    }
};
