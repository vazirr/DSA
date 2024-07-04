//page 46 and 47
/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <queue>
using namespace std;

class node{
    
    public:
    int data;
    node* left;
    node* right;
    
    //constructor
    node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

//building tree
node* buildTree(node* root){
    cout << "Enter the data for the node" <<endl;
    int data;
    cin >> data;
    root = new node(data);
    
    if(data == -1){
        return NULL;
    }
    cout << "Enter data for inserting in left of"<<data << endl;
    root->left = buildTree(root->left); 
    cout << "Enter data for inserting in right of"<<data<<endl;
    root->right = buildTree(root->right);
    
    return root;
}   

//tree traversal
void levelOrderTraversal(node* root){
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    
    while(!q.empty()){
        node* temp = q.front();
       
        q.pop();
        
        if(temp == NULL) {
            //pooraana level completely traverse ho gaya hai
            cout << endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }else{
            cout << temp->data<< " ";
            if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
            
        }
        
    }
    
}

//inorder Traversal

void inOrder(node* root){
    //LNR
    if(root == NULL){
        return;
    }
    inOrder(root->left);
        cout << root->data << endl;
        inOrder(root->right);
}

//preOrder Traversal

void preOrder(node* root){
    //NLR
    if(root == NULL){
        return;
    }
    cout << root->data << endl;
    preOrder(root->left);
    preOrder(root->right);
}

//postOrder Traversal

void postOrder(node* root){
    //LRN
    if(root == NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << endl;
}

int main()
{
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    node* root = NULL;
    //creating a tree
    root = buildTree(root);
  
    //level order
    levelOrderTraversal(root);
    return 0;
}
