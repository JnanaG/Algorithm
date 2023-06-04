#include <iostream>
#include <vector>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 后序遍历二叉树，删除指定节点及其子树，并将其分离为多个树
TreeNode* postorderTraversal(TreeNode* root, int key, std::vector<TreeNode*>& result) {
    if (!root) {
        return nullptr;
    }

    root->left = postorderTraversal(root->left, key, result);
    root->right = postorderTraversal(root->right, key, result);

    if (root->val == key) {
        if (root->left) {
            result.push_back(root->left);
        }
        if (root->right) {
            result.push_back(root->right);
        }
        delete root;
        return nullptr;
    }

    return root;
}

// 中序遍历打印二叉树节点值
void inorderTraversal(TreeNode* root) {
    if (!root) {
        return;
    }

    inorderTraversal(root->left);
    std::cout << root->val << " ";
    inorderTraversal(root->right);
}

int main() {
    // 创建二叉树
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    // 删除节点及其子树，分离为多个独立树
    int key = 2;
    std::vector<TreeNode*> result;
    root = postorderTraversal(root, key, result);

    // 打印分离出的树
    for (TreeNode* tree : result) {
        inorderTraversal(tree);
        std::cout << std::endl;
    }
    system("pause");
    return 0;
}
