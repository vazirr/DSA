
//Approach 1 -----------------------------------------------------------------------------------------------------------------------------
// page 1 - newBook

class Solution
{
    private:
    Node* reverse(Node* head){
        Node* curr = head;
        Node* prev = NULL;
        Node* next = NULL;
        
        while(curr != NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            
            
        }
        return prev;
    }
    void insertAtTail(struct Node* &head, struct Node* &tail, int val){
        Node* temp = new Node(val);
        if(head == NULL){
            head = temp;
            tail = temp;
            return;
            
        }else{
            tail->next = temp;
            tail = temp;
            
        }
        
    }
    struct Node* add(struct Node* num1, struct Node* num2){
        int carry = 0;
        Node* ansHead = NULL;
        Node* ansTail = NULL;
        while(num1 != NULL && num2 != NULL){
            int sum = carry + num1->data + num2-> data;
            int digit = sum%10;
            //create a Node and add in answer LL head
            insertAtTail(ansHead, ansTail, digit);
            carry = sum/10;
            num1 = num1->next;
            num2 = num2->next;
            
        }
        
        while(num1!= NULL){
            int sum = carry + num1 -> data;
            int digit = sum%10;
            insertAtTail(ansHead,ansTail,digit);
            carry = sum/10;
             num1 = num1->next;
        }
        
        while(num2!= NULL){
            int sum = carry + num2 -> data;
            int digit = sum%10;
            insertAtTail(ansHead,ansTail,digit);
            carry = sum/10;
            num2 = num2->next;
            
        }
        
        while(carry!= 0){
            int sum = carry;
            int digit = sum%10;
             insertAtTail(ansHead,ansTail,digit);
            carry = sum/10;
        }
        return ansHead;
    }
    
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* num1, struct Node* num2)
    {
        //step:1 reverse the input ll
        num1 = reverse(num1);
        num2 = reverse(num2);
        
        //step 2 add two linked list
        Node* ans = add(num1, num2);
        
        //step 3 reverse the ans
        
        ans = reverse(ans);
        return ans;
        
    }
};
