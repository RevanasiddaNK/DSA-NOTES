//function Template for C++

//Function to reverse the queue.
//function Template for C++

//Function to reverse the queue.
class Solution
{
    public:
    
    queue<int> rev(queue<int> &q)
    {
        if(q.size() == 1 || q.size() == 0)
            return q;
            
        int element = q.front();
        q.pop();
        rev(q);
        
        q.push(element);
        return q;
    }
};
