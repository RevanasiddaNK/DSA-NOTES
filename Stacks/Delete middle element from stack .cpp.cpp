Delete middle element from stack

#include <bits/stdc++.h> 
void solve(stack<int>&inputStack,int count, int N){
      if(count == N/2){
         inputStack.pop();
         return;
      }

      int element =  inputStack.top();

      inputStack.pop();

      solve(inputStack,++count, N);

      inputStack.push(element);

}


void deleteMiddle(stack<int>&inputStack, int N){
	int count = 0;
  solve(inputStack, count , N);   
}
