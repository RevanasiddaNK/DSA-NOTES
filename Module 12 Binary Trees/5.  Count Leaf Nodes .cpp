/**********************************************************

    Following is the Binary Tree Node class structure:

    template <typename T>
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
    };
    
***********************************************************/

void PostOrderTraversal(BinaryTreeNode<int>* root, int &count){
// LRN Left Node Right
        if(root == NULL)
            return;

        // left
        PostOrderTraversal(root->left, count);

        // right
        PostOrderTraversal(root->right, count);

         // Node
       if(root->left == NULL && root->right == NULL)
            count++;

}


int noOfLeafNodes(BinaryTreeNode<int> *root){
    
    int count = 0;
    PostOrderTraversal(root,count);

    return count;
}
