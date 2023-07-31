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
    cout<<"Enter the data \n";
    root = BuildBinaryTree(root);
// 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1
// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 

    cout<<" Level Order Traversal : \n";
    LevelOrderTraversal(root);

}
