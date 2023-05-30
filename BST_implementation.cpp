#include <iostream>
#include <queue>
#include <stack>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

// Recursive Insertion
TreeNode* insertRecursive(TreeNode* root, int value) {
    if (root == nullptr) {
        return new TreeNode(value);
    }

    if (value < root->val) {
        root->left = insertRecursive(root->left, value);
    }
    else if (value > root->val) {
        root->right = insertRecursive(root->right, value);
    }

    return root;
}

// Iterative Insertion
TreeNode* insertIterative(TreeNode* root, int value) {
    TreeNode* newNode = new TreeNode(value);

    if (root == nullptr) {
        return newNode;
    }

    TreeNode* curr = root;
    TreeNode* parent = nullptr;

    while (curr != nullptr) {
        parent = curr;
        if (value < curr->val) {
            curr = curr->left;
        }
        else if (value > curr->val) {
            curr = curr->right;
        }
        else {
            // Duplicate value, ignore or handle accordingly
            delete newNode;
            return root;
        }
    }

    if (value < parent->val) {
        parent->left = newNode;
    }
    else {
        parent->right = newNode;
    }

    return root;
}

// Recursive Search
TreeNode* searchRecursive(TreeNode* root, int value) {
    if (root == nullptr || root->val == value) {
        return root;
    }

    if (value < root->val) {
        return searchRecursive(root->left, value);
    }
    else {
        return searchRecursive(root->right, value);
    }
}

// Iterative Search
TreeNode* searchIterative(TreeNode* root, int value) {
    TreeNode* curr = root;

    while (curr != nullptr && curr->val != value) {
        if (value < curr->val) {
            curr = curr->left;
        }
        else {
            curr = curr->right;
        }
    }

    return curr;
}

// Recursive In-order Traversal
void inorderRecursive(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    inorderRecursive(root->left);
    std::cout << root->val << " ";
    inorderRecursive(root->right);
}

// Iterative In-order Traversal
void inorderIterative(TreeNode* root) {
    std::stack<TreeNode*> stack;
    TreeNode* curr = root;

    while (curr != nullptr || !stack.empty()) {
        while (curr != nullptr) {
            stack.push(curr);
            curr = curr->left;
        }

        curr = stack.top();
        stack.pop();

        std::cout << curr->val << " ";

        curr = curr->right;
    }
}

int main() {
    TreeNode* root = nullptr;

    // Insertion
    root = insertRecursive(root, 4);
    root = insertRecursive(root, 2);
    root = insertRecursive(root, 6);
    root = insertRecursive(root, 1);
    root = insertRecursive(root, 3);
    root = insertRecursive(root, 5);
    root = insertRecursive(root, 7);

    std::cout << "Recursive In-order Traversal: ";
    inorderRecursive(root);
    std::cout << std::endl;

    std::cout << "Iterative In-order Traversal: ";
    inorderIterative(root);
    std::cout << std::endl;

    // Search
    TreeNode* foundNode = searchRecursive(root, 5);
    if (foundNode != nullptr) {
        std::cout << "Found node (Recursive): " << foundNode->val << std::endl;
    }
    else {
        std::cout << "Node not found (Recursive)" << std::endl;
    }

    foundNode = searchIterative(root, 3);
    if (foundNode != nullptr) {
        std::cout << "Found node (Iterative): " << foundNode->val << std::endl;
    }
    else {
        std::cout << "Node not found (Iterative)" << std::endl;
    }

    return 0;
}
