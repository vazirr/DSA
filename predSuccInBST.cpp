//https://www.naukri.com/code360/problems/_893049?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&leftPanelTabValue=SUBMISSION
//page 84
/*************************************************************

    Following is the Binary Tree node structure
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };

*************************************************************/
pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{
    int pred = -1;
    int succ = -1;
    TreeNode *temp = root;
    
    // Finding the node with the given key
    while (temp != NULL && temp->data != key) {
        if (temp->data > key) {
            succ = temp->data;
            temp = temp->left;
        } else {
            pred = temp->data;
            temp = temp->right;
        }
    }

    // If the key doesn't exist in the tree
    if (temp == NULL) {
        return make_pair(pred, succ);
    }

    // Finding the predecessor
    if (temp->left != NULL) {
        TreeNode *leftTree = temp->left;
        while (leftTree->right != NULL) {
            leftTree = leftTree->right;
        }
        pred = leftTree->data;
    }

    // Finding the successor
    if (temp->right != NULL) {
        TreeNode *rightTree = temp->right;
        while (rightTree->left != NULL) {
            rightTree = rightTree->left;
        }
        succ = rightTree->data;
    }

    return make_pair(pred, succ);
}
