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
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};

        vector<vector<int>> lvlVec;
        queue<pair<TreeNode*, int>> q; // node, height
        q.push({root, 0});

        while(!q.empty()) {
            auto [curr, height] = q.front();
            q.pop();

            if(height >= lvlVec.size()) {
                lvlVec.push_back({curr->val});
            } else {
                lvlVec[height].push_back(curr->val);
            }

            if (curr->left) q.push({curr->left, height+1});
            if (curr->right) q.push({curr->right, height+1});
        } 

        return lvlVec;
    }
};
