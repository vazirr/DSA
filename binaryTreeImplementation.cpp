//page 46 and 47

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
