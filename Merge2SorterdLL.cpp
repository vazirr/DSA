#include <bits/stdc++.h>

/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/


Node<int>* solve(Node<int>* first, Node<int>* second){

    if(first -> next == NULL){
        first -> next = second;
        return first;
    }
    Node<int>* curr1 = first;
    Node<int>* next1 = curr1->next;
    Node<int>* curr2 = second;
    Node<int>* next2 = curr2->next;

    while(next1 != NULL && curr2 != NULL){
        if((curr2 -> data >= curr1 -> data) && (curr2 -> data <= next1 -> data)){

            curr1 -> next = curr2;
            next2 = curr2 -> next;
            curr2 -> next = next1;
            curr1 = curr2;
            curr2 = next2;
        }
        else{
            //means the second list element didnt lie between the first list element
            curr1 = next1;
            next1 = next1 -> next;
            if(next1 == NULL){
                curr1->next = curr2;
                return first;
            }
          
        }
    }
    return first;
}
Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    //first list is empty
    if(first == NULL){
        return second;
    }
    //second list is empty
    if(second == NULL){
        return first;
    }

    //list present
    //check which list first data is small
    if(first -> data <= second -> data){
        return solve(first,second);

    }else{
        return solve(second,first);
    }
    


}
