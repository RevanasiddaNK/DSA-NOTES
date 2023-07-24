#include<stack>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    vector<int>ans(n);
    stack<int>stack1;
    stack1.push(-1);
    for(int i=n-1;i>=0;i--){
        int curr = arr[i];
        while(stack1.top() >= curr){
            stack1.pop();
        }
        ans[i] = stack1.top();
        stack1.push(curr);
        
    }
    return ans;
}
