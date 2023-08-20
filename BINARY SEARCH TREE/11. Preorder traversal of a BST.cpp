#include <bits/stdc++.h> 
/*
    Following is the class structure of BinaryTreeNode class for referance:

    class BinaryTreeNode {
       public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };
*/

/*
Approach 1 
 Time Complexity O(N) 
 SpaceComplexity O(Height of the Tree)
*/








// Brute Force
// Time Complexity O(N*log(N)) 
// SpaceComplexity O(Height of the Tree)

BinaryTreeNode<int>* BalancedTree(vector<int>&arr, int s, int e) {
    
    if(s > e)
        return NULL;
    
    int m = s+(e-s)/2;
    int val = arr[m];
    
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(val);
    
    root->left = BalancedTree(arr, s, m-1);
    root->right = BalancedTree(arr, m+1, e);
    
    return root;
}

BinaryTreeNode<int>* preorderToBST(vector<int> &preorder) {
   
   sort(preorder.begin(), preorder.end());
   
   return BalancedTree(preorder,0,preorder.size()-1);
}
