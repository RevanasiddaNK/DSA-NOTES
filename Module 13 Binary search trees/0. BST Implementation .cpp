#include<iostream>
#include<queue>
using namespace std;

class Node {
        public:

        int data;
        Node* left;
        Node* right;

        Node(int data){
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};

Node* insertToBST(Node* root, int data) {

    if(root == NULL){
        root = new Node(data);
        return root;
    }

    if(root->data > data)
        root->left = insertToBST(root->left, data);
    else
        root->right = insertToBST(root->right, data);

    return root;
}

void CreateBST(Node* &root) {

    cout<<"Enter Data to the BST : \n";
    int data;
    cin>>data;

    while(data != -1) {
        root = insertToBST(root, data);
        cin>>data;
    }
}

void LevelOrderTraversal(Node* root){

        queue<Node*>q;
        q.push(root);
        q.push(NULL);

        while(! q.empty()){
            Node* temp = q.front();
             q.pop();
            
            if(temp == NULL){
                cout<<endl;
                if(!q.empty()){
                    q.push(NULL);
                }
            }

            else{

                cout<<temp->data<<" ";
                // q.pop();

                if(temp->left)
                    q.push(temp->left);

                if(temp->right)
                    q.push(temp->right);
            }
        }
}

int getMinInBST(Node* root) {

    Node* temp = root;
    int min = -9999999;
    while(temp != NULL) {
        min = temp->data;
        temp = temp->left;
    }
    return min;
}

int getMaxInBST(Node* root) {

    Node* temp = root;
    int Max = 9999999;
    while(temp != NULL) {
        Max = temp->data;
        temp = temp->right;
    }
    return Max;
}

Node* DeleteNodeFromBST(Node* root, int data) {

    if(root == NULL) {
        return root;
    }

    else if(root->data == data) {

        // 0 childs
        if(root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        } 

        // 1 chicld on right
        else if(root->left == NULL && root->right != NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }

        // 1 child on left
        else if(root->left != NULL && root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // 2 childs
        else {
/*
            int max = getMaxInBST(root);
            root->data = max;
            root->left = DeleteNodeFromBST(root->left, max);
            return root;
*/          
            int mini = getMaxInBST(root);
            root->data = mini;
            root->right = DeleteNodeFromBST(root->right, mini);
            return root;

        }

    }

    else if(root->data > data) {
        root->left = DeleteNodeFromBST(root->left, data);
        return root;
    }
    else  {
        root->left = DeleteNodeFromBST(root->left, data);
        return root;
    }

}

int main() {

    Node* root = NULL;

    CreateBST(root);

    LevelOrderTraversal(root);

    cout<<" minimum element in a BST : "<<getMinInBST(root)<<endl;
    cout<<" maximum element in a BST : "<<getMaxInBST(root)<<endl;

    int DataToDelete;
    cout<<"Enter Data To Delete from BST : ";
    cin>>DataToDelete;

    root = DeleteNodeFromBST(root,DataToDelete);

    LevelOrderTraversal(root);

}
