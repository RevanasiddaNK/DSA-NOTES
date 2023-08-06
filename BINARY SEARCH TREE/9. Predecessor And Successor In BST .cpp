#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class BinaryTreeNode
    {
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
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

*************************************************************/

pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    int pre = -1;
    int succ = -1;
    BinaryTreeNode<int>* temp = root;
    while(temp != NULL && temp->data != key) {

        if(temp->data > key) {
            succ = temp->data;
            temp = temp->left;
        }
        else {
            pre = temp->data;
            temp = temp->right;
        }
    }
    if(temp != NULL) {
        BinaryTreeNode<int>* keyNode = temp;
        BinaryTreeNode<int>* leftNode = keyNode->left;
        BinaryTreeNode<int>* rightNode = keyNode->right;

        while(rightNode != NULL) {
            succ = rightNode->data;
            rightNode = rightNode->left;
        }

        while (leftNode != NULL) {
            pre = leftNode->data;
            leftNode = leftNode->right;
        }
    }
    
    pair<int,int> ans = make_pair(pre, succ);
    return ans;
}
