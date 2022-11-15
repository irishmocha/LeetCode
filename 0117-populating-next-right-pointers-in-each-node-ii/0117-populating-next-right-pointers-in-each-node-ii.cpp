/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) {
            return root;
        }
        
        queue<Node*> q;
        q.push(root);
        q.push(nullptr);
        while (q.size() > 1) {
            Node* now = q.front(); q.pop();
            if (now == nullptr) {
                q.push(nullptr);
                continue;
            }
            
            now->next = q.front();
            if (now->left) {
                q.push(now->left);
            }
            if (now->right) {
                q.push(now->right);
            }
        }
        return root;
    }
};