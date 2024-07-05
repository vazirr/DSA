//Given a binary tree with n nodes. Find the zig-zag level order traversal of the binary tree.
//In zig zag traversal starting from the first level go from left to right for odd-numbered levels and right to left for even-numbered levels.

//page 56 57
class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
        vector<int> result;
        if(root == NULL){
            return result;
        }
        
        queue<Node*>q;
        q.push(root);
        bool leftToRight = true;
        while(!q.empty()){
            //level ko process karna hai
            int size = q.size();
            vector<int> ans(size);
            
            //level ko process karna hai
            for(int i = 0; i<size; i++){
                Node* frontNode = q.front();
                q.pop();
                
                //normal insert or reverse insert
                int index = leftToRight ? i : size - i - 1;
                ans[index] = frontNode->data;
                 
                 if(frontNode->left){
                     q.push(frontNode->left);
                 }
                 if(frontNode->right){
                     q.push(frontNode->right);
                 }
                 
                
                
            }
            
            //direction change karni padegi
            leftToRight = !leftToRight;
            for(auto i : ans){
                result.push_back(i);
            }
        
        }
        return result;
    }
};
