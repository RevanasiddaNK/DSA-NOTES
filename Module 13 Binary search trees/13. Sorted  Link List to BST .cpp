/* 
GFG 
//Linked List 
struct LNode
{
    int data;
    struct LNode* next;
    
    LNode(int x){
        data = x;
        next = NULL;
    }
};

//Tree
struct TNode  
{  
    
    int data;  
    struct TNode* left;  
    struct TNode* right; 
    TNode(int x)
    {
        data=x;
        left=right=NULL;
    }
}; */








// LeetCode Solution accepted
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
     int valueAtPosition(ListNode* root1, int p) {
        int count = 0;
        ListNode* root = root1;
        while(root != NULL && count < p) {
            count++;
            root = root->next;
        }
        return root->val;
    }
  
    TreeNode* ConstructBST(ListNode* LLroot, int s, int e) {
        
        if(s > e)
            return NULL;
        
        int m = s+(e-s)/2;   
        int data = valueAtPosition(LLroot,m);
        
         TreeNode* root = new  TreeNode(data);
         
         root->left = ConstructBST(LLroot,s,m-1);
         root->right = ConstructBST(LLroot,m+1,e);
         
         return root;
    }
  

    TreeNode* sortedListToBST(ListNode* head) {
         
        int len = 0;
        ListNode* temp = head;
        while(temp != NULL){
            len++;
            temp = temp->next;
        }
        
        return ConstructBST(head,0,len-1);
    }
};
