// 5/11 Test Cases Passed
class TrieNode{
    
    public:
        char data;
        TrieNode* children[26];
        bool isTerminal;
        int countChildren;
        
        TrieNode(char ch){
            
            data = ch;
            isTerminal = false;
            int countChildren = 0;

            for(int i=0; i<26; i++)
                children[i] = NULL;              
        }
};

class Trie{
    
    public:
    
        TrieNode* root;
        Trie(char ch){
            root = new TrieNode(ch);
        }

        void InsertToTrie(string word){
            insert(word, root);
        }
    
        void insert(string word, TrieNode* root){
            
            if(word.length() == 0){
                root->isTerminal = true;
                return;
            }
            
            int index = word[0]-'a';
            
            TrieNode* child;
            
            
            if(root->children[index] != NULL)
                child = root->children[index];
            else{
                child = new TrieNode(word[0]);
                root->countChildren++;
                root->children[index] = child;
            }
            
            insert(word.substr(1), child);
        }

        void LCR(string str, string &ans){
            
            for(int i=0; i<str.size(); i++){
                
                if(root->countChildren == 1){
                    char ch = str[i];
                    int index = ch-'a';
                    ans.push_back(ch);
                    root = root->children[index];
                }
                else{
                    break;
                }
                
                if(root->isTerminal)
                    break;
            }   
        }    
};

string longestCommonPrefix(vector<string> &arr, int n)
{
    Trie* T = new Trie('\0');
    
    for(int i=0; i<arr.size(); i++)
        T->InsertToTrie(arr[i]);

    string str = arr[0];
    string ans = "";
    
    T->LCR(str,ans);
    
    return ans;
    
}
