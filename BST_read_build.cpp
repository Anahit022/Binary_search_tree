#include <iostream>
#include <fstream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

TreeNode* insertIntoBST(TreeNode* root, int value) {
    if (root == nullptr) {
        return new TreeNode(value);
    }

    if (value < root->val) {
        root->left = insertIntoBST(root->left, value);
    }
    else if (value > root->val) {
        root->right = insertIntoBST(root->right, value);
    }

    return root;
}

TreeNode* buildBSTFromFile(const std::string& filename) {
    std::ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return nullptr;
    }

    int value;
    inputFile >> value;

    TreeNode* root = new TreeNode(value);

    while (inputFile >> value) {
        insertIntoBST(root, value);
    }

    inputFile.close();
    return root;
}

void inorderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    inorderTraversal(root->left);
    std::cout << root->val << " ";
    inorderTraversal(root->right);
}

int main() {
    std::string filename = "bst.txt";
    TreeNode* root = buildBSTFromFile(filename);

    if (root == nullptr) {
        std::cout << "Failed to build the binary search tree from file." << std::endl;
    }
    else {
        std::cout << "Binary search tree built from file: ";
        inorderTraversal(root);
        std::cout << std::endl;
    }

    return 0;
}
