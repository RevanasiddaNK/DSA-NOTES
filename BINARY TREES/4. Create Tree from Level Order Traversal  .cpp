
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

void buildFromLevelOrder(Node* &root){

        int rootData;
        cout<<"Enter root Data : ";
        cin>>rootData;

        root = new Node(rootData);

        queue< Node* >q;
        q.push(root);

        while(! q.empty()){

            Node* temp = q.front();
            q.pop();

            int LeftData;
            cout<<"Enter Left Data for "<<temp->data<<"  : ";
            cin>>LeftData;

            if(LeftData != -1) {
                temp->left = new Node(LeftData);
                q.push(temp->left);
            }

            int RightData;
            cout<<"Enter Right Data for  "<<temp->data <<"  : ";
            cin>>RightData;

            if(RightData != -1) {
                temp->right = new Node(RightData);
                q.push(temp->right);
            }
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
    buildFromLevelOrder(root);

    cout<<" Level Order Traversal : \n";
    LevelOrderTraversal(root);

}
