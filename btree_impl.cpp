#include <vector>
#include <algorithm>
#include <limits.h>
#include <iostream>
#include <queue>

struct TreeNode {
    TreeNode* left;
    TreeNode* right;
    int val = INT_MIN;
};

/*
       1
    2    3
  4  5 6  7
*/
std::vector<std::vector<int>> traverse_level(TreeNode* root) {
    std::queue<TreeNode*> q;
    std::vector<std::vector<int>> tree;
    std::vector<int> level;
    
    q.push(root);
    q.push(nullptr);

    while (!q.empty()) {
        TreeNode* front = q.front();

        if (front) {
            level.push_back(front->val);
            if (front->left) q.push(front->left);
            if (front->right) q.push(front->right);
        } else {
            if (level.size() > 0) {
                tree.push_back(level);
                level.clear();

                q.push(nullptr);
            }
        }
        
        q.pop();
    }

    return tree;
}

int main() {
    TreeNode* root;
    root->val = 1;

    TreeNode* l2;
    l2->val = 2;
    root->left = l2;

    TreeNode* r2;
    r2->val = 3;
    root->right = r2;

    TreeNode* ll3;
    ll3->val = 4;
    l2->left = ll3;

    TreeNode* lr3;
    lr3->val = 5;
    l2->right = lr3;

    TreeNode* rl3;
    rl3->val = 6;
    r2->left = rl3;

    TreeNode* rr3;
    rr3->val = 7;
    r2->right = rr3;

    std::vector<std::vector<int>> res;
    res = traverse_level(root);

    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            std::cout << res[i][j] << " ";
        }

        std::cout << "\n";
    }

    return 0;
}