/**
In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.

Two nodes of a binary tree are cousins if they have the same depth, but have different parents.

We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.

Return true if and only if the nodes corresponding to the values x and y are cousins.

 */



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int x;
    int y;
    int yDepth;
    int xDepth;
    TreeNode * xNode;
    TreeNode * yNode;
    TreeNode * xParent;
    TreeNode * yParent;
public:
    void recurse(TreeNode * node, TreeNode * prevNode, int depth){
        if(node == nullptr){
            return;
        }
        else if(node->val == x){
            xDepth = depth;
            xNode = node;
            xParent = prevNode;
            
            return;
        }
        else if(node->val == y){
            yDepth = depth;
            yNode = node;
            yParent = prevNode;
            return;
        }
        else{
            recurse(node->right, node, depth+1);
            recurse(node->left, node, depth+1);
        }
    }
    bool isCousins(TreeNode* root, int x, int y) {
        this->x = x;
        this->y = y;
        recurse(root, nullptr, 0);
        return xDepth == yDepth && xParent != yParent;
        
    }
};
