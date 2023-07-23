
void pushAtBottom(stack<int>& myStack, int x) 
{
    if(myStack.empty()){
        myStack.push(x);
        return;
    }

    int element = myStack.top();

    myStack.pop();

    pushAtBottom(myStack,x);

    myStack.push(element);

}


void reverseStack(stack<int> &stack) {
    if(stack.empty())
        return;
    
    int element = stack.top();

    stack.pop();
    reverseStack(stack);

    pushAtBottom(stack,element);
    
}
