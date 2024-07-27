
//https://www.naukri.com/code360/problems/flatten-bst-to-a-sorted-list_1169459?leftPanelTab=0&leftPanelTabValue=PROBLEM
//page 87
#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
void inOrder(TreeNode<int>* root, vector<int> &inOrderVal){
    if(root == NULL){
        return;
    }

    inOrder(root->left,inOrderVal);
    inOrderVal.push_back(root->data);
    inOrder(root->right,inOrderVal);

}

TreeNode<int>* flatten(TreeNode<int>* root)
{
   vector<int> inOrderVal;
//store inorder -> sorted values
   inOrder(root, inOrderVal);
    int n = inOrderVal.size();

   TreeNode<int>* newRoot = new TreeNode<int>(inOrderVal[0]);
   TreeNode<int>* curr = newRoot;

   for(int i = 1; i < n; i++){
       TreeNode<int>* temp = new TreeNode<int>(inOrderVal[i]);
       curr -> left = NULL;
       curr ->right = temp;
       curr = temp; 
   }

   //3rd step
   curr->left = NULL;
   curr->right = NULL;

   return newRoot;
}
