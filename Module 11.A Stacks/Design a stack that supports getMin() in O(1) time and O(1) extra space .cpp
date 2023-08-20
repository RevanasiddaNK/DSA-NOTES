#include<stack>
class SpecialStack {
    public:
       stack<int>s;
       int mini = INT_MIN; 
    void push(int data) {
        if(s.empty()){
            s.push(data);
            mini = data;
        }
        else{
            if(data >= mini){
                s.push(data);
            }
            else{
                int value = 2*data - mini;
                mini = data;
                s.push(value);
            }
        }
    }

    void pop() {

        if(s.empty())
            return;
        int curr = s.top();

        if(curr < mini){
            mini = 2*mini - curr;
        }
        s.pop();

    }

    int top() {
        if(s.empty())
            return -1;

        int curr = s.top();   
        if(curr < mini){
            int trueValue = mini;
            return mini;
        }

        return curr;
    }

    int getMin() {
        if(s.empty())
            return -1;
        return mini;
    }  
};
