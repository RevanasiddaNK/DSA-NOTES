
class Solution {
	public:
		string FirstNonRepeating(string A){
		    
		    string ans = "";
		    
//  queue is used because we have to acces front element(bcz FirstNonRepeating char) 
//  delete that if not FirstNonRepeating char
		    queue<int>q;
		    
// map is used to count the number of times each charachter arrived first
		    unordered_map<char, int >count;
		    
		    // For traversing each elements in a string 
		    // s.length() and s.size() both are correct
		    for(int i=0;i <A.length();i++){
		        
		        char ch = A[i];
		        
		        q.push(ch);
		        
		    //    updating count by no. of times of its occurence
		        count[ch]++;
		        
	            while(!q.empty()){
		            
		            if(count[q.front()] > 1)
		            // q.front() is repeating
		                q.pop();
		            else
		            {
		            // q.front() is non repeating
		                ans.push_back(q.front());
		                break;
		            }
		        }
		        
		        //  q.front() is repeating
		        if(q.empty())
		            ans.push_back('#');
		    }
		    return ans;
		}
};
