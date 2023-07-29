#include<iostream>
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
    cout<<"Enter the data \n";
    cin>>data;

     root = new Node(data);

    if(data == -1){
        return NULL;
    }

    root = new Node(data);

    cout << "Enter data for inserting in left of " << data << endl;
    root->left = BuildBinaryTree(root->left);

    cout << "Enter data for inserting in right of " << data << endl;
    root->right  = BuildBinaryTree(root->right);

    return root;
}

int main() {
    Node* root = NULL;
    root = BuildBinaryTree(root);
}