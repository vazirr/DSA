void insertAtBottom(stack<int> &stack, int n){
    if(stack.empty()){
        stack.push(n);
        return;
    }

    int top = stack.top();
    stack.pop();
    insertAtBottom(stack,n);
    stack.push(top);
}
void reverseStack(stack<int> &stack) {
   
    if(stack.empty()){
        return;
    }
    int num = stack.top();
    stack.pop();

    //recurssive call
    reverseStack(stack);
    insertAtBottom(stack, num);

   }
