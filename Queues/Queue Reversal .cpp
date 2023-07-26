class Solution
{
    public:
    
    queue<int> rev(queue<int> &q)
    {
        stack<int>stk;
        while(q.size() != 0){
            stk.push(q.front());
            q.pop();
        }
        
        while(stk.size() != 0){
            q.push(stk.top());
            stk.pop();
        }
        return q;
    }
};
