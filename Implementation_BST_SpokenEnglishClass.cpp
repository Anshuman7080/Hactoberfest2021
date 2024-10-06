#include <iostream>
#include <queue>

using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

Node* insert_BST(Node* tree, int val) {
    if (tree == nullptr) {
        cout << val << " is inserted into BST successfully" << endl;
        return new Node(val);
    }
    if (val <= tree->data) {
        tree->left = insert_BST(tree->left, val);
    } else {
        tree->right = insert_BST(tree->right, val);
    }
    return tree;
}

bool searchInBST(Node* root, int k) {
    if (root == nullptr) return false;
    if (root->data == k) return true;
    return (k < root->data) ? searchInBST(root->left, k) : searchInBST(root->right, k);
}

Node* findMin(Node* node) {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

Node* delete_BST(Node* tree, int val) {
    if (tree == nullptr) {
        cout << "Value is not present in BST" << endl;
        return tree;
    }

    if (val < tree->data) {
        tree->left = delete_BST(tree->left, val);
    } else if (val > tree->data) {
        tree->right = delete_BST(tree->right, val);
    } else {
        // Node to be deleted found
        if (tree->left == nullptr) {
            Node* temp = tree->right;
            delete tree;
            return temp;
        } else if (tree->right == nullptr) {
            Node* temp = tree->left;
            delete tree;
            return temp;
        }

        // Node with two children: get the inorder successor (smallest in the right subtree)
        Node* temp = findMin(tree->right);
        tree->data = temp->data;  // Copy the inorder successor's value
        tree->right = delete_BST(tree->right, temp->data);  // Delete the inorder successor
    }
    return tree;
}

void inorder(Node* tree) {
    if (tree != nullptr) {
        inorder(tree->left);
        cout << tree->data << " ";
        inorder(tree->right);
    }
}

void printLevelATNewLine(Node* root) {
    if (root == nullptr) return;

    queue<Node*> q;
    q.push(root);
    q.push(nullptr);  // Marker for end of level

    while (!q.empty()) {
        Node* node = q.front();
        q.pop();
        if (node == nullptr) {
            cout << endl;  // End of level
            if (!q.empty()) {
                q.push(nullptr);  // Add marker for next level
            }
        } else {
            cout << node->data << " ";
            if (node->left != nullptr) {
                q.push(node->left);
            }
            if (node->right != nullptr) {
                q.push(node->right);
            }
        }
    }
}

int main() {
    cout << "BRITISH COUNCIL CLASS" << endl;
    Node* root = nullptr;
    int z = 0;

    while (z != 6) {
        cout << "*****************" << endl;
        cout << "Enter 1: To Insert student" << endl;
        cout << "Enter 2: To Search for any student" << endl;
        cout << "Enter 3: if any student exits" << endl;
        cout << "Enter 4: To print the tree in order" << endl;
        cout << "Enter 5: To print level wise" << endl;
        cout << "Enter 6: To Exit" << endl;
        cout << "*****************" << endl;

        cin >> z;
        switch (z) {
            case 1: {
                cout << "Enter the student roll no. as they enter the class: ";
                int id;
                cin >> id;
                root = insert_BST(root, id);
                break;
            }
            case 2: {
                cout << "Enter the student Roll No. for search: ";
                int k;
                cin >> k;
                cout << (searchInBST(root, k) ? "Student is PRESENT in the class" : "Student is NOT PRESENT in the class") << endl;
                break;
            }
            case 3: {
                cout << "Enter the student's Roll No. who exited: ";
                int m;
                cin >> m;
                root = delete_BST(root, m);
                break;
            }
            case 4:
                inorder(root);
                cout << endl;
                break;
            case 5:
                printLevelATNewLine(root);
                break;
            case 6:
                break;
            default:
                cout << "Invalid option. Please try again." << endl;
                break;
        }
    }
    cout << "*******EXIT********" << endl;

    // Cleanup memory (not implemented, but good practice)
    // Ideally, we should implement a function to delete the entire BST.
    
    return 0;
}
