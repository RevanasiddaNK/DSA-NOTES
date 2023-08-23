// Recursive Approach and returns a Node of Starting Index
void BST2SortedLL(TreeNode<int>*root, TreeNode<int>* &head) {
    
    if(root == NULL)
        return;
    
    BST2SortedLL(root->right,head);
    root->right = head;
    
    if(head != NULL)
      head->left = root;
        
    head = root;
    BST2SortedLL(root->left,head);
      
}

TreeNode<int>* flatten(TreeNode<int>* root)
{
    TreeNode<int>*head = NULL;
    BST2SortedLL(root,head);
    head->left = NULL;
    
    TreeNode<int>*curr = head;
    
    while(curr != NULL){
        curr->left = NULL;
        curr = curr->right;
    }
    return head;
}
