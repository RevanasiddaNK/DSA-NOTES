
/* BST Node
struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};
*/
class Solution
{
    public:
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        pre = NULL;
        suc = NULL;
        Node* temp = root;
         
        while(temp != NULL && temp->key!= key) {

            if(temp->key > key) {
                suc = temp;
                temp = temp->left;
            }
            else {
                pre = temp;
                temp = temp->right;
            }
        }
        
        if(temp != NULL) {
            Node* keyNode = temp;
            Node* leftNode = keyNode->left;
            Node* rightNode = keyNode->right;

            while(rightNode != NULL) {
                suc = rightNode;
                rightNode = rightNode->left;
            }

            while (leftNode != NULL) {
                pre = leftNode;
                leftNode = leftNode->right;
            }
        }
    }
};
