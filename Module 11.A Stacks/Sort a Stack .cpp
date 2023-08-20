#include <bits/stdc++.h> 
void insertAtCorrectPosition(stack<int> &stack,int element){

		if( stack.empty() || (! stack.empty() && stack.top() < element)){
			stack.push(element);
			return;
		}

		int a = stack.top();
		stack.pop();

		insertAtCorrectPosition(stack, element);

		stack.push(a);
}

void sortStack(stack<int> &stack)
{	
	if(stack.empty())
		return;

	int element = stack.top();
	stack.pop();

	sortStack(stack);

	insertAtCorrectPosition(stack,element);

}
