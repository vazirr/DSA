
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
