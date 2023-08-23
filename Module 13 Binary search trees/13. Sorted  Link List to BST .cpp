/* 
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




// 2 / 175 test cases passed
class Solution{
  public:
  
    int valueAtPosition(LNode* root, int p) {
        int count = 0;
        while(root != NULL && count < p) {
            count++;
            root = root->next;
        }
        return root->data;
    }
  
    TNode* ConstructBST(LNode* LLroot, int s, int e) {
        
        if(s > e)
            return NULL;
        
        int m = s+(e-s)/2;   
        int data = valueAtPosition(LLroot,m);
        
         TNode* root = new  TNode(data);
         
         root->left = ConstructBST(LLroot,s,m-1);
         root->right = ConstructBST(LLroot,m+1,e);
         
         return root;
    }
  
    TNode* sortedListToBST(LNode *head) {
        
        int len = 0;
        LNode* temp = head;
        while(temp != NULL){
            len++;
            temp = temp->next;
        }
        
        return ConstructBST(head,0,len-1);
    }
};
