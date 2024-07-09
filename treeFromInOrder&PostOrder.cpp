//https://www.geeksforgeeks.org/problems/tree-from-postorder-and-inorder/1

//page no 72

class Solution {
  public:
  
  
    void createMapping(int in[], map<int,int> &nodeToIndex, int n){
        for(int i = 0; i< n ; i++){
            nodeToIndex[in[i]] = i;
        }
      
    }
    
       
    Node* solve(int in[],int post[],int &postOrderIndex,int inOrderStart, int inOrderEnd, int n, map<int,int> &nodeToIndex ){
        
        // base case
        if(postOrderIndex <  0 || inOrderStart > inOrderEnd){
            return NULL;
        }
        
        int element = post[postOrderIndex--];
        Node* root = new Node(element);
        
        int position = nodeToIndex[element];
        // int position = findPosition(in, element,n);
        
        
        //recurssive call
        root->right = solve(in,post,postOrderIndex, position + 1, inOrderEnd,n,nodeToIndex);
        root->left = solve(in,post,postOrderIndex, inOrderStart, position -1,n,nodeToIndex);
        return root;
    }
    // Function to return a tree created from postorder and inoreder traversals.
    Node *buildTree(int n, int in[], int post[]) {
        // Your code here
        
        
        int postOrderIndex = n - 1;
        map<int,int> nodeToIndex;
        createMapping(in, nodeToIndex, n);
       Node* ans =  solve(in,post,postOrderIndex,0,n-1,n, nodeToIndex);
    
        return ans;
    }
};
