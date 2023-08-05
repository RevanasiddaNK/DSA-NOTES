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

int main() {

    Node* root = NULL;

    CreateBST(root);

    LevelOrderTraversal(root);

}
