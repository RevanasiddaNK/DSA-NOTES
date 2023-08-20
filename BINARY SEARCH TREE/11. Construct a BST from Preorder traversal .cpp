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
BinaryTreeNode<int>* ConstructBST(vector<int> &arr, int &i, int min, int max) {
        
        if(i >= arr.size())
            return NULL;
            
        if( arr[i] < min || arr[i] > max)
            return NULL;
        
        BinaryTreeNode<int>* root = new BinaryTreeNode<int>(arr[i++]);
    
        // if(min <= arr[i] && arr[i]  <= currData ){
            root->left = ConstructBST(arr,i,min,root->data);
        
       // else if(currData < arr[i] && arr[i] < max )
            root->right = ConstructBST(arr,i,root->data,max);
    
        return root;
}

BinaryTreeNode<int>* preorderToBST(vector<int> &preorder) {
   int i=0;
   return ConstructBST(preorder,i,INT_MIN,INT_MAX);
}







/*     
    Brute Force
                Time Complexity O(N*log(N)) 
                SpaceComplexity O(Height of the Tree)
*/

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
