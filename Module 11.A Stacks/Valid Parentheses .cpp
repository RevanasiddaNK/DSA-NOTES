#include<stack>
bool isValidParenthesis(string s)
{

    stack<char>stack1;
    for(int i=0; i<s.length(); i++){
        char ch = s[i];

        // if it is a Opening Bracket
        if(ch == '(' || ch == '{' || ch == '['){
            stack1.push(ch);
        }
        else
        {   
            // It is a closing Bracket
            if(stack1.empty()){
                return false;;
            }
            else
            {
                char ch2 = stack1.top();
                if ((ch2 == '(' && ch == ')') || (ch2 == '{' && ch == '}') ||
                    (ch2 == '[' && ch == ']')) {
                        stack1.pop();
                  } 
                  else 
                  {
                    return false;
                  }
                }
            }
        }
        
    if(stack1.empty())
        return true;
    else
        return false;
}

