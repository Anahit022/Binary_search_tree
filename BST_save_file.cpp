#include <iostream>
#include <fstream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

void saveBSTToFile(TreeNode* root, std::ofstream& outputFile) {
    if (root == nullptr) {
        return;
    }

    // In-order traversal: left subtree, current node, right subtree
    saveBSTToFile(root->left, outputFile);
    outputFile << root->val << " ";
    saveBSTToFile(root->right, outputFile);
}

void saveBSTToFileWrapper(TreeNode* root, const std::string& filename) {
    std::ofstream outputFile(filename);
    if (!outputFile.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return;
    }

    saveBSTToFile(root, outputFile);

    outputFile.close();
    std::cout << "Binary search tree saved to file: " << filename << std::endl;
}

int main() {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7);

    std::string filename = "bst.txt";
    saveBSTToFileWrapper(root, filename);

    return 0;
}
