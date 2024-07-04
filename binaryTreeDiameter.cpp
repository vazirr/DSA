
//approach #1  having time complexity  = O(n^2)
//page 52

class Solution {
  public:
  
  int height(Node* root){
      
      if(root==NULL){
          return 0;
      }
      
      int left = height(root->left);
      int right = height(root->right);
      int ans = max(left,right) + 1;
      return ans;
  }
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
        //base case
        if(root == NULL){
            return 0;
        }
        
        int op1 = diameter(root->left);
        int op2 = diameter(root->right);
        int op3 = height(root->left) + height(root->right) + 1;
        
        int ans = max(op1, max(op2,op3));
        
        return ans;
    }
};
