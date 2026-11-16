class Solution {
public:

    vector<TreeNode*> generate(int start, int end) {

        vector<TreeNode*> result;

        if (start > end) {
            result.push_back(nullptr);
            return result;
        }

        for (int i = start; i <= end; i++) {

            vector<TreeNode*> leftTrees = generate(start, i - 1);

            vector<TreeNode*> rightTrees = generate(i + 1, end);

            for (auto left : leftTrees) {
                for (auto right : rightTrees) {

                    TreeNode* root = new TreeNode(i);

                    root->left = left;
                    root->right = right;

                    result.push_back(root);
                }
            }
        }

        return result;
    }

    vector<TreeNode*> generateTrees(int n) {
        return generate(1, n);
    }
};