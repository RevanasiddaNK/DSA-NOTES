#include <bits/stdc++.h> 
int findMinimumCost(string str) {

    // ODD Case
    if(str.length()&1)
        return -1;

    stack<char>stack1;

    for(int i=0;i<str.length();i++){
      char ch = str[i];
      if(ch == '{')
          stack1.push(ch);
      else{
          if( !stack1.empty() && stack1.top() == '{')
                stack1.pop();
          else
                stack1.push(ch);
      }
    }

    int a = 0, b = 0;
    while(!stack1.empty()){
      if(stack1.top() == '{')
          a++;
      else
          b++;

      stack1.pop();
    }

    int ans = (a+1)/2 + (b+1)/2;

    return ans;
}
