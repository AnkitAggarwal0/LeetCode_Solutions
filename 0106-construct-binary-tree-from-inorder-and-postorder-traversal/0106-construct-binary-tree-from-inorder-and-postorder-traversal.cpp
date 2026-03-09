#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    unordered_map<int, int> inorderIdx;
    int postIdx;

public:
    TreeNode* build(vector<int>& postorder, int left, int right) {
        if (left > right) return nullptr;

        // The root is the last element in the current postorder range
        int rootVal = postorder[postIdx--];
        TreeNode* root = new TreeNode(rootVal);

        // Find where this root splits the inorder array
        int mid = inorderIdx[rootVal];

        // Build Right Subtree then Left Subtree 
        // because postorder is visited (Left, Right, Root)
        root->right = build(postorder, mid + 1, right);
        root->left = build(postorder, left, mid - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        postIdx = postorder.size() - 1;
        for (int i = 0; i < inorder.size(); ++i) {
            inorderIdx[inorder[i]] = i;
        }
        return build(postorder, 0, inorder.size() - 1);
    }
};