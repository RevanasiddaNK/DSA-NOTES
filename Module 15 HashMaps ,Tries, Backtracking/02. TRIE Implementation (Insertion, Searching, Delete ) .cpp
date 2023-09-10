#include<iostream>
using namespace std;

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

// Searching Operation

    bool SearchInTrie(string word ){
        return search(word,root);
    }

    bool search(string word , TrieNode *root ){
    // BASE CASE
        if(word.length() == 0)
            return root->isTerminal;

    //PROCESSING
        int index = word[0]-'A';
        TrieNode *child;

        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else
            return false;

        return search(word.substr(1), child);

    }
// DELETING OPERATION
    void DeleteFromTrie(string word){
        Delete_(word, root);
    }
// CHECKING WHETHER ROOT IS EMPTY
    bool IsEmpty(TrieNode *root){

        if(root == NULL)
            return true;
        
        for(int i=0; i<26; i++){
            if(root->children[i] != NULL)
                return true;
        }
        return false;

    }

    void Delete_(string word, TrieNode *root){

        if(word.length() == 0) {
            root->isTerminal = false;
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

        Delete_(word.substr(1),child);

        if(IsEmpty(root) && root->isTerminal == false){
            delete(root);
            root = NULL;
        }

    }

};

int main() {

    Trie *T = new Trie();
    string word = "WORDSOFDICTIONARY";
    string word1 = "REVANASIDDA";
    
    T->insertToTrie(word);
    cout<<"is "<<word<<" present in Trie ? : "<<T->SearchInTrie(word)<<endl;

  //  cout<<"is "<<word1<<" present in Trie ? : "<<T->SearchInTrie(word1)<<endl;
    T->insertToTrie(word1);
 //   cout<<"is "<<word1<<" present in Trie ? : "<<T->SearchInTrie(word1)<<endl;

    cout<<"is "<<word1<<" present in Trie ? : "<<T->SearchInTrie(word1)<<endl;
    T->DeleteFromTrie(word1);
    cout<<"is "<<word1<<" present in Trie ? : "<<T->SearchInTrie(word1)<<endl;

    return 0;
}
