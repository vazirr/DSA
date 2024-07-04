//page 50 51

class Solution{
    public:
   
    int height(struct Node* node){
       //base case
       if(node == NULL){
           return 0;
       }
       
       //two heights for subtree 
       int left = height(node -> left);
       int right = height(node -> right);
       
       int ans = max(left, right) + 1;
       return ans;
        
    }
};
