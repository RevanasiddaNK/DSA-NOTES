// User function template for C++

// trie node
/*
struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];

    // isLeaf is true if the node represents
    // end of a word
    bool isLeaf;
};
*/

//Function to insert string into TRIE.
void insert(struct TrieNode *root, string word)
{
     if(word.length() == 0) {
            root->isLeaf = true;
            return;
        }

        int index = word[0]-'a';

        struct TrieNode* child;
        if(root->children[index] != NULL)
            child = root->children[index];
        else{
            child = getNode();
            root->children[index] = child;
        }

        insert(child,word.substr(1));
}

//Function to use TRIE data structure and search the given string.
bool search(struct TrieNode *root, string word) 
{
    // BASE CASE
        if(word.length() == 0)
            return root->isLeaf;

    //PROCESSING
        int index = word[0]-'a';
        struct TrieNode *child;

        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else
            return false;

        return search(child,word.substr(1));

}
