/*
 * Author:
 * Date:
 * Name:
 */

//problem 10
#include <iostream>
#include <vector>

class TreeNode {
public:
    int data;
    TreeNode* left, *right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    TreeNode* root;
    void insert(TreeNode*& node, int value);
    void remove(TreeNode*& node, int value);
    void printInOrder(TreeNode* node);
    int height(TreeNode* node);
    int depth(TreeNode* node, int value);
    TreeNode* rotateRight(TreeNode* node);
    TreeNode* rotateLeft(TreeNode* node);
    int balanceFactor(TreeNode* node);
    void balance(TreeNode*& node);

public:
    BinarySearchTree() : root(nullptr) {}
    void add(int value) { insert(root, value); }
    void remove(int value) { remove(root, value); }
    void print() { printInOrder(root); std::cout << std::endl; }
    int height() { return height(root); }
    int depth(int value) { return depth(root, value); }
    void convertToAVL() { if (root) convertToAVL(root->left), convertToAVL(root->right), balance(root); }
};

void BinarySearchTree::insert(TreeNode*& node, int value) {
    if (!node) node = new TreeNode(value);
    else if (value < node->data) insert(node->left, value);
    else if (value > node->data) insert(node->right, value);
}

void BinarySearchTree::remove(TreeNode*& node, int value) {
    if (!node) return;
    if (value < node->data) remove(node->left, value);
    else if (value > node->data) remove(node->right, value);
    else {
        if (!node->left && !node->right) delete node, node = nullptr;
        else if (!node->left) { TreeNode* temp = node; node = node->right; delete temp; }
        else if (!node->right) { TreeNode* temp = node; node = node->left; delete temp; }
        else { TreeNode* successor = node->right; while (successor->left) successor = successor->left;
            node->data = successor->data; remove(node->right, successor->data);
        }
    }
    balance(node);
}

void BinarySearchTree::printInOrder(TreeNode* node) {
    if (node) printInOrder(node->left), std::cout << node->data << " ", printInOrder(node->right);
}

int BinarySearchTree::height(TreeNode* node) {
    return node ? 1 + std::max(height(node->left), height(node->right)) : 0;
}

int BinarySearchTree::depth(TreeNode* node, int value) {
    if (!node) return -1;
    if (value == node->data) return 0;
    int childDepth = (value < node->data) ? depth(node->left, value) : depth(node->right, value);
    return (childDepth == -1) ? -1 : 1 + childDepth;
}

TreeNode* BinarySearchTree::rotateRight(TreeNode* node) {
    TreeNode* newRoot = node->left; node->left = newRoot->right; newRoot->right = node; return newRoot;
}

TreeNode* BinarySearchTree::rotateLeft(TreeNode* node) {
    TreeNode* newRoot = node->right; node->right = newRoot->left; newRoot->left = node; return newRoot;
}

int BinarySearchTree::balanceFactor(TreeNode* node) {
    return height(node->left) - height(node->right);
}

void BinarySearchTree::balance(TreeNode*& node) {
    int bf = balanceFactor(node);
    if (bf > 1) { if (balanceFactor(node->left) < 0) node->left = rotateLeft(node->left); node = rotateRight(node); }
    else if (bf < -1) { if (balanceFactor(node->right) > 0) node->right = rotateRight(node->right); node = rotateLeft(node); }
}

int main() {
    BinarySearchTree bst;
    std::vector<int> values = {34, 62, 1, 46, 11, 0, 32, 3, 1, 2};

    for (int value : values) bst.add(value);

    std::cout << "Binary Search Tree (In-order): ";
    bst.print();

    bst.convertToAVL();

    std::cout << "AVL Tree (In-order): ";
    bst.print();

    return 0;
}
//Problem 1-4
#include <iostream>

enum Color { RED, BLACK };

class Node {
public:
    int data;
    Color color;
    Node* left, *right, *parent;

    Node(int val) : data(val), color(RED), left(nullptr), right(nullptr), parent(nullptr) {}
};

class RedBlackTree {
private:
    Node* root;

    void leftRotate(Node* x);
    void rightRotate(Node* x);
    void insertFix(Node* newNode);
    void deleteFix(Node* x);
    void transplant(Node* u, Node* v);
    void deleteNode(Node* z);
    void printTree(Node* root, int space);

public:
    RedBlackTree() : root(nullptr) {}

    void Insert(int value);
    void Delete(int value);
    void PrintTree();
    void ReverseTree();
};

void RedBlackTree::leftRotate(Node* x) {
    Node* y = x->right;
    x->right = y->left;

    if (y->left != nullptr)
        y->left->parent = x;

    y->parent = x->parent;

    if (x->parent == nullptr)
        root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;

    y->left = x;
    x->parent = y;
}

void RedBlackTree::rightRotate(Node* y) {
    Node* x = y->left;
    y->left = x->right;

    if (x->right != nullptr)
        x->right->parent = y;

    x->parent = y->parent;

    if (y->parent == nullptr)
        root = x;
    else if (y == y->parent->left)
        y->parent->left = x;
    else
        y->parent->right = x;

    x->right = y;
    y->parent = x;
}

void RedBlackTree::insertFix(Node* z) {
    while (z->parent != nullptr && z->parent->color == RED) {
    
    }
    root->color = BLACK;
}

void RedBlackTree::deleteFix(Node* x) {
    while (x != root && x->color == BLACK) {
   
    }
    x->color = BLACK;
}

void RedBlackTree::transplant(Node* u, Node* v) {
 
}

void RedBlackTree::deleteNode(Node* z) {
  
}

void RedBlackTree::printTree(Node* root, int space) {
  
}

void RedBlackTree::Insert(int value) {
    Node* newNode = new Node(value);
    Node* y = nullptr;
    Node* x = root;

    while (x != nullptr) {
        y = x;
        if (newNode->data < x->data)
            x = x->left;
        else
            x = x->right;
    }

    newNode->parent = y;

    if (y == nullptr)
        root = newNode;
    else if (newNode->data < y->data)
        y->left = newNode;
    else
        y->right = newNode;

    insertFix(newNode);
}

void RedBlackTree::Delete(int value) {
  
}

void RedBlackTree::PrintTree() {
    printTree(root, 0);
}

void RedBlackTree::ReverseTree() {
  
}

int main() {
    int N, value;

    std::cin >> N;

    RedBlackTree tree;

    for (int i = 0; i < N; ++i) {
        std::cin >> value;
        tree.Insert(value);
    }

    std::cout << "Original Tree:" << std::endl;
    tree.PrintTree();

    tree.ReverseTree();

    std::cout << "\nReversed Tree:" << std::endl;
    tree.PrintTree();

    return 0;
}
//Problem 7-8
#include <iostream>
#include <vector>

enum Color { RED, BLACK };

class Node {
public:
    int data;
    Color color;
    Node* left, *right, *parent;

    Node(int val) : data(val), color(RED), left(nullptr), right(nullptr), parent(nullptr) {}
};

class RedBlackTree {
private:
    Node* root;

    void leftRotate(Node* x);
    void rightRotate(Node* x);
    void insertFix(Node* newNode);
    void deleteFix(Node* x);
    void transplant(Node* u, Node* v);
    void deleteNode(Node* z);
    void printTree(Node* root, int space);
    Node* search(Node* root, int value, int& height);
    int getHeight(Node* node);
    void inorderTraversal(Node* node, std::vector<int>& values);

public:
    RedBlackTree() : root(nullptr) {}

    void Insert(int value);
    void Delete(int value);
    void PrintTree();
    void ReverseTree();
    void search(int value);
    void median();
};

void RedBlackTree::leftRotate(Node* x) {   
}

void RedBlackTree::rightRotate(Node* x) {
 
}

void RedBlackTree::insertFix(Node* newNode) {
   
}

void RedBlackTree::deleteFix(Node* x) {
  
}

void RedBlackTree::transplant(Node* u, Node* v) {
  
}

void RedBlackTree::deleteNode(Node* z) {

}

void RedBlackTree::printTree(Node* root, int space) {
   
}

Node* RedBlackTree::search(Node* root, int value, int& height) {
   
    return nullptr;
}

int RedBlackTree::getHeight(Node* node) {
    
    return 0;
}

void RedBlackTree::inorderTraversal(Node* node, std::vector<int>& values) {
   
}

void RedBlackTree::Insert(int value) {
   
}

void RedBlackTree::Delete(int value) {
   
}

void RedBlackTree::PrintTree() {
   
    printTree(root, 0);
}

void RedBlackTree::ReverseTree() {
   
}

void RedBlackTree::search(int value) {
    int height = 0;
    Node* result = search(root, value, height);

    if (result) {
        std::cout << value << " is found, its height is " << height << std::endl;
    } else {
        std::cout << value << " is not found" << std::endl;
    }
}

void RedBlackTree::median() {
    std::vector<int> values;
    inorderTraversal(root, values);

    if (!values.empty()) {
        int size = values.size();
        int medianIndex = size / 2;

        if (size % 2 == 0) {
            std::cout << values[medianIndex - 1] << " and " << values[medianIndex] << " are medians" << std::endl;
        } else {
            std::cout << values[medianIndex] << " is median" << std::endl;
        }
    }
}

int main() {
    int N, value, searchValue;

    std::cin >> N;

    RedBlackTree tree;

    for (int i = 0; i < N; ++i) {
        std::cin >> value;
        tree.Insert(value);
    }

    tree.PrintTree();

    std::cout << "Enter search value: ";
    std::cin >> searchValue;
    tree.search(searchValue);

    tree.median();

    return 0;
}
//Problem 6
class Node:
    def __init__(self, key):
        self.key = key
        self.parent = None
        self.left = None
        self.right = None
        self.color = 'RED'


class RedBlackTree:
    def __init__(self):
        self.NIL = Node(0)
        self.NIL.color = 'BLACK'
        self.root = self.NIL

    def insert(self, key):
        node = Node(key)
        node.parent = None
        node.left = self.NIL
        node.right = self.NIL
        node.color = 'RED'

        y = None
        x = self.root

        while x != self.NIL:
            y = x
            if node.key < x.key:
                x = x.left
            else:
                x = x.right

        node.parent = y
        if y is None:
            self.root = node
        elif node.key < y.key:
            y.left = node
        else:
            y.right = node

        if node.parent is None:
            node.color = 'BLACK'
            return

        if node.parent.parent is None:
            return

        self.fix_insert(node)

    def fix_insert(self, k):
        while k.parent.color == 'RED':
            if k.parent == k.parent.parent.right:
                u = k.parent.parent.left
                if u.color == 'RED':
                    u.color = 'BLACK'
                    k.parent.color = 'BLACK'
                    k.parent.parent.color = 'RED'
                    k = k.parent.parent
                else:
                    if k == k.parent.left:
                        k = k.parent
                        self.right_rotate(k)
                    k.parent.color = 'BLACK'
                    k.parent.parent.color = 'RED'
                    self.left_rotate(k.parent.parent)
            else:
                u = k.parent.parent.right

                if u.color == 'RED':
                    u.color = 'BLACK'
                    k.parent.color = 'BLACK'
                    k.parent.parent.color = 'RED'
                    k = k.parent.parent
                else:
                    if k == k.parent.right:
                        k = k.parent
                        self.left_rotate(k)
                    k.parent.color = 'BLACK'
                    k.parent.parent.color = 'RED'
                    self.right_rotate(k.parent.parent)
            if k == self.root:
                break
        self.root.color = 'BLACK'

    def left_rotate(self, x):
        y = x.right
        x.right = y.left
        if y.left != self.NIL:
            y.left.parent = x

        y.parent = x.parent
        if x.parent is None:
            self.root = y
        elif x == x.parent.left:
            x.parent.left = y
        else:
            x.parent.right = y
        y.left = x
        x.parent = y

    def right_rotate(self, x):
        y = x.left
        x.left = y.right
        if y.right != self.NIL:
            y.right.parent = x

        y.parent = x.parent
        if x.parent is None:
            self.root = y
        elif x == x.parent.right:
            x.parent.right = y
        else:
            x.parent.left = y
        y.right = x
        x.parent = y

    def black_height(self, node):
        if node == self.NIL:
            return 1
        left_black_height = self.black_height(node.left)
        right_black_height = self.black_height(node.right)
        if left_black_height != right_black_height:
            print(f"{node.key} - {min(left_black_height, right_black_height) + 1}")
        return left_black_height + (1 if node.color == 'BLACK' else 0)

    def display_black_height(self):
        self.black_height(self.root)

if __name__ == "__main__":
    n = int(input())
    values = list(map(int, input().split()))

    rbt = RedBlackTree()
    for value in values:
        rbt.insert(value)

    rbt.display_black_height()
//Problem 9
    #include <iostream>

enum Color { RED, BLACK };

class Node {
public:
    int data;
    Color color;
    Node* left, *right, *parent;

    Node(int val) : data(val), color(RED), left(nullptr), right(nullptr), parent(nullptr) {}
};

class RedBlackTree {
private:
    Node* root;

    void leftRotate(Node* x);
    void rightRotate(Node* x);
    void insertFix(Node* newNode);
    void deleteFix(Node* x);
    void transplant(Node* u, Node* v);
    void deleteNode(Node* z);
    void printTree(Node* root, int space);
    int countNodesInSubtree(Node* node);

public:
    RedBlackTree() : root(nullptr) {}

    void Insert(int value);
    void Delete(int value);
    void PrintTree();
    void ReverseTree();
    void countNodesInSubtrees();
};

void RedBlackTree::leftRotate(Node* x) {
  
}

void RedBlackTree::rightRotate(Node* x) {
   
}

void RedBlackTree::insertFix(Node* newNode) {
   
}

void RedBlackTree::deleteFix(Node* x) {
   
}

void RedBlackTree::transplant(Node* u, Node* v) {
    
}

void RedBlackTree::deleteNode(Node* z) {
    
}

void RedBlackTree::printTree(Node* root, int space) {
    
}

int RedBlackTree::countNodesInSubtree(Node* node) {
    if (node == nullptr) {
        return 0;
    } else {
        return 1 + countNodesInSubtree(node->left) + countNodesInSubtree(node->right);
    }
}

void RedBlackTree::Insert(int value) {
    
}

void RedBlackTree::Delete(int value) {
    
}

void RedBlackTree::PrintTree() {
 
    printTree(root, 0);
}

void RedBlackTree::ReverseTree() {
   
}

void RedBlackTree::countNodesInSubtrees() {
    std::cout << "Number of nodes in each subtree:" << std::endl;
    
    int count = countNodesInSubtree(root);
    std::cout << "Root - " << count << " nodes" << std::endl;
}

int main() {
    int N, value;

    std::cin >> N;

    RedBlackTree tree;

    for (int i = 0; i < N; ++i) {
        std::cin >> value;
        tree.Insert(value);
    }

    std::cout << "Original Tree:" << std::endl;
    tree.PrintTree();

    tree.ReverseTree();

    std::cout << "\nReversed Tree:" << std::endl;
    tree.PrintTree();

    tree.countNodesInSubtrees();

    return 0;
}
