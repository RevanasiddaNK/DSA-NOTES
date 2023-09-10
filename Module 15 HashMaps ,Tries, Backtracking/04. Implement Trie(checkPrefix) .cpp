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

    /** Initialize your data structure here. */
    TrieNode *root;
    Trie() {
        root = new TrieNode('\0');
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Insert(word,root);
    }

    void Insert(string word, TrieNode *root){

        if(word.length() == 0) {
            root->isTerminal = true;
            return;
        }

        int index = word[0]-'a';

        TrieNode* child;
        if(root->children[index] != NULL)
            child = root->children[index];
        else{
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        Insert(word.substr(1),child);
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
         return SearchInTrie(word,root);
    }

    bool SearchInTrie(string word , TrieNode *root ){
    // BASE CASE
        if(word.length() == 0)
            return root->isTerminal;

    //PROCESSING
        int index = word[0]-'a';
        TrieNode *child;

        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else
            return false;

        return SearchInTrie(word.substr(1), child);

    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return checkPrefix(prefix,root);
    }

    bool checkPrefix(string word , TrieNode *root ){
    // BASE CASE
        if(word.length() == 0)
            return true;

    //PROCESSING
        int index = word[0]-'a';
        TrieNode *child;

        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else
            return false;

        return checkPrefix(word.substr(1), child);

    }
};
