/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

//approach 1: ---------------------------------------------------------------------------------------

Node* sortList(Node *head){
    int zeroCount = 0;
    int oneCount = 0;
    int twoCount = 0;

    Node* temp = head;

    while(temp != NULL){
        if(temp->data == 0){
            zeroCount++;
        }else if(temp->data == 1){
            oneCount++;
        }else if(temp->data == 2){
            twoCount++;
        }
        temp = temp -> next;
    }

    temp = head;

    while(temp != NULL){
        if(zeroCount != 0){
            temp -> data = 0;
            zeroCount--;
        }else if(oneCount !=0){
            temp->data = 1;
            oneCount--;


        }else if(twoCount != 0){
            temp -> data = 2;
            twoCount--;
        }
        temp = temp -> next;
    }

    return head;

}

//approach 2: ---------------------------------------------------------------------------------------


void insertAtTail(Node* &tail, Node*curr){
    tail->next = curr;
    tail = curr;
} 
Node* sortList(Node *head){
    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;
    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;
    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;

    Node* curr = head;
    //created a separated list of 0's, 1's and 2's.
    while(curr!=NULL){
        int value = curr->data;
        if(value == 0){
            insertAtTail(zeroTail,curr);
        }
        else if(value == 1){
            insertAtTail(oneTail,curr);
        }else if(value == 2){
            insertAtTail(twoTail,curr);
        }
        curr = curr->next;
    }
    //merge 3sublist
    //1's List is not empty
    if(oneHead->next != NULL){
        zeroTail->next = oneHead->next;
    }else{
        zeroTail->next = twoHead->next;

    }

    oneTail->next = twoHead->next;
    twoTail->next =NULL;

    //setup head
    head = zeroHead->next;
    return head;

}

//Approach 3 ---------------------------------------------------------------------------------------------------------------------------------------------------


