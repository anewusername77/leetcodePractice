#include <iostream>
#include <vector>

using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    public:
        bool isBalanced(TreeNode* root) {
            if(root == nullptr) return true;
            if(abs(depth(root->left)-depth(root->right)) <= 1){
                return isBalanced(root->left) && isBalanced(root->right);
            }
            else {
                return false;
            }
        }

        int depth(TreeNode* root){
            if(root == nullptr) return 0;
            return max(depth(root->left), depth(root->right))+1;
        }
};