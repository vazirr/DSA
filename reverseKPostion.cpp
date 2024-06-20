/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

Node* kReverse(Node* head, int k) {
    // Write your code here.
    //base case
    if(head == NULL){
        return NULL;
    }
    //reverse 1st k notes
    Node* forward = NULL;
    Node* curr = head;
    Node* prev = NULL;
    int cnt = 0;

    while(curr!=NULL && cnt < k){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        cnt++;
    }

    //step 2: recurrsion dekhlega aage ka
    if(forward != NULL){
        head->next = kReverse(forward,k);

    }
    //step 3 return head of reverse list
    return prev;
}
