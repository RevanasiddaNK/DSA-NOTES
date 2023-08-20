#include <bits/stdc++.h> 
bool findRedundantBrackets(string &s)
{
   stack<char>stack1;

   for(int i=0;i<s.length();i++){
       char ch = s[i];
       if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/'){
           stack1.push(ch);
       }
       else
       {    
          
            if(ch == ')'){
                bool isRebundant = true;

           while(stack1.top() != '(' ){

               char ch1 = stack1.top();

               if(ch1 == '+' || ch1 == '-' || ch1 == '*' || ch1 == '/')
                   isRebundant = false;

               stack1.pop();
           }

            if(isRebundant)
                return true;
            else
                stack1.pop();

        }

        }
    }
    
    return false;
    

}
