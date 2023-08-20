class Solution{
  public:
    vector<int> nextSmaller(int *heights,int n){
        vector<int>ans(n);
        stack<int>stack1;
        stack1.push(-1);
        for(int i=n-1;i>=0;i--){
            int curr = heights[i];
        while(stack1.top() != -1 && heights[stack1.top()] >= curr){
            stack1.pop();
        }
        ans[i] = stack1.top();
        stack1.push(i);     
    }
        return ans;
    }

    vector<int> prevSmaller(int *heights,int n){
        vector<int>ans(n);
        stack<int>stack1;
        stack1.push(-1);
        for(int i=0;i < n;i++){
            int curr = heights[i];
        while(stack1.top() != -1 && heights[stack1.top()] >= curr){
            stack1.pop();
        }
        ans[i] = stack1.top();
        stack1.push(i);     
    }
        return ans;
    }

    int largestRectangleArea(int *heights , int n) {


        vector<int>next(n);
        next = nextSmaller(heights,n);

        vector<int>prev(n);
        prev = prevSmaller(heights,n);
        int area = INT_MIN;
        for(int i=0;i<n;i++){
            int l = heights[i];

            if(next[i] == -1)
                next[i] = n;

            int b = next[i] - prev[i] - 1;
            int Newarea = l*b;
            area = max(area , Newarea);
        }
        return area;
    }
  
    
    int maxArea(int M[MAX][MAX], int n, int m) {
        
        int area = largestRectangleArea(M[0],m);
        
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                
                if(M[i][j] != 0)
                    M[i][j] = M[i][j]+M[i-1][j];
                
            }
            area = max(area,largestRectangleArea(M[i],m));
        }
            
        return area;

    }
};
