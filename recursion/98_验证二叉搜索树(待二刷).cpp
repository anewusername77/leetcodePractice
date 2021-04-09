#include <iostream>
#include <vector>
#include <map>
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
    bool isValidBST(TreeNode* root) {
        if(root == nullptr) return true;
        
        return compare(root, LONG_MIN, LONG_MAX);
        
    }

    bool compare(TreeNode* node, long long lower, long long upper){
        if(node == nullptr) return true;
        if(node->val <= lower || node->val >= upper) return false;
        return compare(node->left, lower, node->val) && compare(node->right, node->val, upper);
       
    }

    
};