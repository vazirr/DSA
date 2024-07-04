
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

//approach #2   having time complexity O(n)
// Function to return the diameter of a Binary Tree.
    pair<int,int> diameterFast(Node* root){
        if(root == NULL){
            pair<int,int> p = make_pair(0,0);
            //pair <int,int> shows diameter and height
            return p;
        }
        pair<int,int> left = diameterFast(root->left);
        pair<int,int> right = diameterFast(root->right);
        
        int op1 = left.first;
        int op2 = right.first;
        int op3 = left.second + right.second + 1;
        
        
        pair<int,int> ans;
        ans.first = max(op1,max(op2,op3));
        ans.second = max(left.second, right.second) + 1;
        
        
        return ans;
        
    }
    int diameter(Node* root) {
        //base case
        return diameterFast(root).first;
        
        
    }
};
