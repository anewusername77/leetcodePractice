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
    int maxPathSum(TreeNode* root) {
        if(root == nullptr) return 0;
        int maxsum = INT_MIN;
        maxSum(root, maxsum);

        return maxsum;
    }

    int maxSum(TreeNode* node, int& maxsum){
        if(node == nullptr) return 0;
        //只有大于0的才选
        int leftmax = max(maxSum(node->left, maxsum), 0);
        int rightmax = max(maxSum(node->right, maxsum), 0);

        int nodemax = node->val + leftmax + rightmax;  //更新节点处的最大路径和

        maxsum = max(nodemax, maxsum);
        
        return node->val + max(leftmax, rightmax);  //返回以该节点为root的贡献值
    }
};