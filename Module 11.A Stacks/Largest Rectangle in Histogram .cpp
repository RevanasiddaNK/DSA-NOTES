#include<bits/stdc++.h>
int largestRectangle(vector<int>&heights) {
  
  int n = heights.size();
  stack<int>st;
  vector<int>leftSmaller(n,0);
  for(int i=0; i<n; i++){

    while(!st.empty() && heights[st.top()] >= heights[i])
      st.pop();
    
    if(st.empty())
      leftSmaller[i] = 0;
    else
      leftSmaller[i] = st.top()+1;

    st.push(i);

  }

  while(!st.empty())
    st.pop();

  vector<int>RightSmaller(n,0);
  for(int i=n-1; i>=0; i--){

    while(!st.empty() && heights[st.top()] >= heights[i])
      st.pop();
    
    if(st.empty())
      RightSmaller[i] = n-1;
    else
      RightSmaller[i] = st.top()-1;

    st.push(i);

  }

  int maxArea = INT_MIN;
  for(int i=0; i<n; i++){
    int area = (RightSmaller[i] - leftSmaller[i] + 1) *heights[i];
    maxArea = max(maxArea,area);
  }
  return maxArea;
}
