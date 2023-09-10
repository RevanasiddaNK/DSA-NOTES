// Not solved
class TrieNode{
    public:
        char data;
        TrieNode* children[26];
        bool isTerminal;
        
        TrieNode(char ch) {
            data = ch;
            for(int i=0; i<26; i++)
                children[i] = NULL;       
            isTerminal = false; 
        }
};

class Trie {
    public:
    TrieNode *root;
    // constructor
    Trie(){
        root = new TrieNode('\0');
    }

// Insertion Operation
    void insertToTrie(string word){
        Insert(word,root);
    }

    void Insert(string word, TrieNode *root){

        if(word.length() == 0) {
            root->isTerminal = true;
            return;
        }

        int index = word[0]-'A';

        TrieNode* child;
        if(root->children[index] != NULL)
            child = root->children[index];
        else{
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        Insert(word.substr(1),child);
    }

    vector<vector<string>> GETSuggestions(string s){
                
        vector<vector<string>>output;
        TrieNode *prev = root;
        string prefix = "";
                
        for(int i=0; i<s.length(); i++){
                    
            char LastChar = s[i];
            prefix.push_back(LastChar);
                    
            //int index = LastChar-'a';
            TrieNode * curr = prev->children[LastChar-'a'];
                    
            if(curr == NULL)
                break;
                
            vector<string>temp;
            PRINTSuggestions(curr,temp,prefix);
            output.push_back(temp);
            temp.clear();
                        
            // updating prev
            prev = curr;
                        
        }
                
        return output;
    }
        
    void PRINTSuggestions(TrieNode * curr,vector<string>&temp, string prefix){
            
        if(curr->isTerminal)
            temp.push_back(prefix);
            // why not return is not used here;
                
            for(char i = 'a'; i <= 'z'; i++){
                    
                TrieNode* next = curr->children[i-'a'];
                    
                if(next != NULL){
                    prefix.push_back(i);
                    PRINTSuggestions(next,temp,prefix);
                    prefix.pop_back();
                }
            }
        }
};


vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr)
{
    Trie* t = new Trie();
    for(int i=0; i<contactList.size(); i++){
        t->insertToTrie(contactList[i]);
    }
    
    return t->GETSuggestions(queryStr);
    
}
