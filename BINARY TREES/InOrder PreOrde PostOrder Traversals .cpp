#include<iostream>
#include<queue>
using namespace std;

class Node {
    
    public :
   // private :
        int data;
        Node* right;
        Node* left;

 //   public :
        Node(int data){
            this->data = data;
            right = NULL;
            left = NULL;
        }
};

Node* BuildBinaryTree(Node* root) {

    int data;
    cin>>data;
 
    if(data == -1) {
        return NULL;
    }

    root = new Node(data);

    root->left = BuildBinaryTree(root->left);
    root->right  = BuildBinaryTree(root->right);

    return root;
}

void InOrderTraversal(Node* root){
// LNR Left Node Right
        if(root == NULL)
            return;

        // left
        InOrderTraversal(root->left);

        // Node
        cout<<root->data<<"  ";

        // right
        InOrderTraversal(root->right);

}

void PreOrderTraversal(Node* root){
// NLR  Node Left Right
        if(root == NULL)
            return;

         // Node
        cout<<root->data<<"  ";

        // left
        PreOrderTraversal(root->left);


        // right
        PreOrderTraversal(root->right);

}

void PostOrderTraversal(Node* root){
// LRN Left Node Right
        if(root == NULL)
            return;

        // left
        PostOrderTraversal(root->left);

        // right
        PostOrderTraversal(root->right);

         // Node
        cout<<root->data<<"  ";

}

int main() {

    Node* root = NULL;
    cout<<"Enter the data \n";
    root = BuildBinaryTree(root);
// 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1
// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 

    cout<<" In Order Traversal : \n";
    InOrderTraversal(root);

    cout<<"\n Pre Order Traversal : \n";
    PreOrderTraversal(root);

    cout<<"\n Post Order Traversal : \n";
    PostOrderTraversal(root);

}
