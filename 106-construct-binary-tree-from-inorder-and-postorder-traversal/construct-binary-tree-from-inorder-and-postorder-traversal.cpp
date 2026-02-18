#include <vector>
#include <unordered_map>

using namespace std;
class Solution {
    int postIdx;
    unordered_map<int, int> inMap;

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        postIdx = n - 1; 
        for (int i = 0; i < n; i++) {
            inMap[inorder[i]] = i;
        }

        return solve(postorder, 0, n - 1);
    }

    TreeNode* solve(vector<int>& postorder, int inStart, int inEnd) 
    {
        if (inStart > inEnd) return nullptr;
        int rootVal = postorder[postIdx--];
        TreeNode* root = new TreeNode(rootVal);
        int mid = inMap[rootVal];
        root->right = solve(postorder, mid + 1, inEnd);
        root->left = solve(postorder, inStart, mid - 1);
        return root;
    }
};