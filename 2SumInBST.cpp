//https://www.naukri.com/code360/problems/two-sum-in-a-bst_1062631?leftPanelTab=0&leftPanelTabValue=SUBMISSION
//page no 86
#include <bits/stdc++.h> 
// Following is the Binary Tree node structure
/**************
class BinaryTreeNode {
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
    
};
***************/
void inOrder(BinaryTreeNode<int>* root, vector<int> &inOrderVal){
    if(root == NULL){
        return;
    }

    inOrder(root->left,inOrderVal);
    inOrderVal.push_back(root->data);
    inOrder(root->right, inOrderVal);
}
bool twoSumInBST(BinaryTreeNode<int>* root, int target) {   
	vector<int> inOrderVal;
    //store inorder sorted values
    inOrder(root,inOrderVal);
    //use two pointer approach
    int i = 0;
    int j = inOrderVal.size() - 1;

//check the target val
    while(i < j){
        int sum = inOrderVal[i] + inOrderVal[j];
        //checking target
        if(sum == target){
            return true;
        }
        //sum greater then target
        else if(sum > target){
            j--;
            //sum less than target
        }else{
            i++;
        }


    }
    return false;

}
