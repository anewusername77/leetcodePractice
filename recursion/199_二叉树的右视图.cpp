#include <iostream>
#include <vector>
#include <queue>

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
        vector<int> rightSideView(TreeNode* root) {
            if (root == nullptr) return {};
            vector<int> rightview;
            levelorder(root, rightview);
            return rightview;

        }
        void levelorder(TreeNode* root, vector<int> & rightView){
            queue<TreeNode*> q;
            int curlevelsize = 1;
            q.push(root);
            TreeNode *tmp;
            while(!q.empty()){
                while(curlevelsize > 1){
                    tmp = q.front();
                    q.pop();
                    if(tmp->left != nullptr) q.push(tmp->left);
                    if(tmp->right != nullptr) q.push(tmp->right);
                    curlevelsize --;
                }
                tmp = q.front();
                rightView.push_back(tmp->val);
                q.pop();
                if(tmp->left != nullptr) q.push(tmp->left);
                if(tmp->right != nullptr) q.push(tmp->right);

                curlevelsize = q.size();
            }
        }
};