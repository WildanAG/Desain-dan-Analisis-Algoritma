#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

// Fungsi untuk membuat node baru
Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Fungsi untuk menyisipkan data ke Tree (secara rekursif)
Node* insert(Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }

    return root;
}

// Traversal Preorder
void preorder(Node* root) {
    if (root != NULL) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

// Traversal Inorder
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

// Traversal Postorder
void postorder(Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

int main() {
    Node* root = NULL;
    int n, value;

    cout << "Masukkan jumlah node: ";
    cin >> n;

    cout << "Masukkan " << n << " angka:\n";
    for (int i = 0; i < n; ++i) {
        cin >> value;
        root = insert(root, value);
    }

    cout << "\nTraversal Preorder: ";
    preorder(root);

    cout << "\nTraversal Inorder: ";
    inorder(root);

    cout << "\nTraversal Postorder: ";
    postorder(root);

    cout << endl;
    return 0;
}

