/**********************************************************

    Following is the Binary Tree Node class structure:

    template <typename T>
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
    
***********************************************************/
void inOrderTraversal(BinaryTreeNode<int> *root, int &count){
    //LNR
    if(root == NULL){
        return;
    }

    inOrderTraversal(root->left, count);
    //leaf node
    if(root->left == NULL && root->right == NULL){
        count++;
    }
    inOrderTraversal(root->right, count);

}
int noOfLeafNodes(BinaryTreeNode<int> *root){
    int count = 0;
    inOrderTraversal(root,count);
return count;
}
