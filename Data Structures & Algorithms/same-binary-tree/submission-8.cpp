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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<pair<TreeNode*, TreeNode*>> st;
        st.push({p, q});

        while (!st.empty()) {
            auto [currP, currQ] = st.top();
            st.pop();

            if (!currP && !currQ) continue;
            if (!currP && currQ) return false;
            if (currP && !currQ) return false;
            if (currP->val != currQ->val) return false;

            st.push({currP->left, currQ->left});
            st.push({currP->right, currQ->right});
        }

        return true;
    }
};
