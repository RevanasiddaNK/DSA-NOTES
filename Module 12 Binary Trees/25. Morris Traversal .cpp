// Inorder Tree Traversal without recursion and without stack & Queue LNR
// Time complexity O(N)
// Space Complexity O(1)

void MorrisTraversalInOrder(struct tNode* root)
{
    struct tNode *current, *pre;
 
    if (root == NULL)
        return;
 
    current = root;
    while (current != NULL) {
 
        if (current->left == NULL) {
            cout << current->data << " ";
            current = current->right;
        }
        else {
 
            /* Find the inorder predecessor of current */
            pre = current->left;
            while (pre->right != NULL
                   && pre->right != current)
                pre = pre->right;
 
            /* Make current as the right child of its
               inorder predecessor */
            if (pre->right == NULL) {
                pre->right = current;
                current = current->left;
            }
 
            /* Revert the changes made in the 'if' part to
               restore the original tree i.e., fix the right
               child of predecessor */
            else {
                pre->right = NULL;
                cout << current->data << " ";
                current = current->right;
            } 
        } 
    } 
}

// Preorder traversal without recursion and without stack NLR

void morrisTraversalPreorder(node* root)
{
    
    while (root)
    {
        // If left child is null, print the current node data. Move to
        // right child.
        if (root->left == NULL)
        {
            cout<<root->data<<" ";
            root = root->right;
        }
        else
        {
            // Find inorder predecessor
            node* current = root->left;
            while (current->right && current->right != root)
                current = current->right;
 
            // If the right child of inorder predecessor already points to
            // this node
            if (current->right == root)
            {
                current->right = NULL;
                root = root->right;
            }
 
            // If right child doesn't point to this node, then print this
            // node and make right child point to this node
            else
            {
                cout<<root->data<<" ";
                current->right = root;
                root = root->left;
            }
        }
    }
}

// // Morris Traversal for Postorder LRN
vector<int> postorderTraversal(TreeNode* root)
{
    vector<int> res;
    TreeNode* current = root;
 
    while (current != NULL) {
        // If right child is null,
        // put the current node data
        // in res. Move to left child.
        if (current->right == NULL) {
            res.push_back(current->key);
            current = current->left;
        }
        else {
            TreeNode* predecessor = current->right;
            while (predecessor->left != NULL
                   && predecessor->left != current) {
                predecessor = predecessor->left;
            }
            // If left child doesn't point
            // to this node, then put in res
            // this node and make left
            // child point to this node
            if (predecessor->left == NULL) {
                res.push_back(current->key);
                predecessor->left = current;
                current = current->right;
            }
            // If the left child of inorder predecessor
            // already points to this node
            else {
                predecessor->left = NULL;
                current = current->left;
            }
        }
    }
    // reverse the res
    reverse(res.begin(), res.end());
    return res;
}


