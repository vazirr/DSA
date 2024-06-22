
//approach 1 -------------------------------------------------------------------------------------------------------
//page 2-3 newBook

Solution
{
    private:
    void insertAtTail(Node* &head, Node* &tail, int d){
        Node* temp = new Node(d);
        if(head == NULL){
            head = temp;
            tail = temp;
            return;
            
        }else{
            tail->next = temp;
            tail = temp;
        }
    }
    public:
    Node *copyList(Node *head)
    {
       //step 1 create a clone list using next
       Node* cloneHead = NULL;
       Node* cloneTail = NULL;
       Node* temp  = head;
       while(temp!=NULL){
               insertAtTail(cloneHead,cloneTail,temp->data);
               temp = temp->next;
           }
           
        //step 2 create a map
        unordered_map<Node*,Node*> oldToNew;
        Node* originalNode = head;
        Node* cloneNode = cloneHead;
        while(originalNode!=NULL && cloneNode!= NULL){
             oldToNew[originalNode] = cloneNode;
             originalNode = originalNode ->next;
             cloneNode = cloneNode ->next;
        }
        originalNode = head;
        cloneNode = cloneHead;
        
        while(originalNode!=NULL){
            cloneNode -> arb = oldToNew[originalNode -> arb];
            cloneNode = cloneNode -> next;
            originalNode = originalNode -> next;
        }
        
        return cloneHead;
       
       
    }




//approach 2: ----------------------------------------------------------------------------------------------------------------------------------------------------------
private:
    void insertAtTail(Node* &head, Node* &tail, int val){
        
        Node* newNode = new Node(val);
        
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
        }
    }
    public:
    Node *copyList(Node *head)
    {
        //step 1 create a clone
        
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        
        Node* temp = head;
        while(temp!= NULL){
            insertAtTail(cloneHead,cloneTail,temp->data);
            temp = temp->next;
        }
        
             
             
        //step 2 : cloneNode add in between original Node
        
         Node* originalNode = head;
         Node* cloneNode = cloneHead;
         while(originalNode != NULL && cloneNode!=NULL){
             Node* next = originalNode->next;
             originalNode->next = cloneNode;
             originalNode = next;
             
             next = cloneNode->next;
             cloneNode->next = originalNode;
             cloneNode = next;
             
         }
        
        //step 3 : copy the random ptr
        temp = head;
        while(temp != NULL){
            if(temp->next != NULL){
                if(temp->arb != NULL){
                    temp->next->arb = temp->arb->next;
                    
                }else{
                    temp->next = temp->arb;
                }
                
                
            }
            
            temp = temp->next->next;
            
            
            
            
        }
        //step 4 : revert the step 2
        
        originalNode = head;
        cloneNode = cloneHead;
        while(originalNode != NULL && cloneNode!=NULL){
            originalNode -> next = cloneNode->next;
            originalNode  = originalNode->next;
            if(originalNode != NULL){
                
            cloneNode->next = originalNode ->next;
                
            }
            
            cloneNode = cloneNode->next;
        }
        
        //step 5: return ans
        return cloneHead;
        
    }

};
