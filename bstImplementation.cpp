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
        
        node(int data){
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
        
        
        
};

node* insertIntoBst(node* root, int data){
    //base case
    if(root == NULL){
        root = new node(data);
        return root;
    }
    
    if(data > root ->data){
        //right part me insert karna hai
        root ->right = insertIntoBst(root->right,data);
    }else{
        //left part me insert karna hai
        root->left = insertIntoBst(root->left,data);
    }
    return root;
}

void takeInp(node* &root){
    int data;
    cin >> data;
    
    while(data != -1){
       root =  insertIntoBst(root,data);
        cin >> data;
    }
}   
void levelOrderTraversal(node* root){
    
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        
        if(temp == NULL){
            //pooraana level complete ho chuka hai
            cout << endl;
            
            if(!q.empty()){
                //queue has some child nodes
                q.push(NULL);
            }
            
        }else{
            cout << temp->data << " ";
            
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
            
            
        }
        
    }



}
int main()
{
    
    node* root = NULL;
    cout << "Enter data to create bst"<<endl;
    takeInp(root);
    cout << "Printing the BST"<< endl;
    levelOrderTraversal(root);
   
}
