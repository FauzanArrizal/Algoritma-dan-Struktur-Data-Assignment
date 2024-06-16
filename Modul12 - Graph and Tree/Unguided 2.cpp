#include <iostream>
#include <queue>

using namespace std;

struct TNode {
    int data;
    TNode *left;
    TNode *right;

    // Konstruktor
    TNode(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

void preOrder(TNode *node) {
    if (node != NULL) {
        cout << node->data << " ";
        preOrder(node->left);
        preOrder(node->right);
    }
}

void inOrder(TNode *node) {
    if (node != NULL) {
        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }
}

void postOrder(TNode *node) {
    if (node != NULL) {
        postOrder(node->left);
        postOrder(node->right);
        cout << node->data << " ";
    }
}

void printChild(TNode *node) {
    if (node != NULL) {
        cout << "Anak Dari " << node->data << " : ";
        if (node->left != NULL) {
            cout << node->left->data << " ";
        }
        if (node->right != NULL) {
            cout << node->right->data << " ";
        }
        if (node->left == NULL && node->right == NULL) {
            cout << "Tidak Ada Anak.";
        }
        cout << endl;
    }
}

void printDescendant(TNode *node) {
    if (node != NULL) {
        if (node->left != NULL || node->right != NULL) {
            cout << "Turunan Dari " << node->data << " : ";
            queue<TNode*> q;
            if (node->left != NULL) q.push(node->left);
            if (node->right != NULL) q.push(node->right);
            while (!q.empty()) {
                TNode* temp = q.front();
                q.pop();
                cout << temp->data << " ";
                if (temp->left != NULL) q.push(temp->left);
                if (temp->right != NULL) q.push(temp->right);
            }
            cout << endl;
        } else {
            cout << "Turunan Dari " << node->data << " : Tidak Ada Turunan." << endl;
        }
    }
}

TNode* findNode(TNode* node, int value) {
    if (node == NULL) return NULL;
    if (node->data == value) return node;
    TNode* foundNode = findNode(node->left, value);
    if (foundNode == NULL) {
        foundNode = findNode(node->right, value);
    }
    return foundNode;
}

TNode* findParent(TNode* root, TNode* node) {
    if (root == NULL || root == node) return NULL;
    if (root->left == node || root->right == node) return root;
    TNode* foundNode = findParent(root->left, node);
    if (foundNode == NULL) {
        foundNode = findParent(root->right, node);
    }
    return foundNode;
}

void deleteNode(TNode* &root, int value) {
    TNode* node = findNode(root, value);
    if (node == NULL) {
        cout << "Node tidak ditemukan!" << endl;
        return;
    }

    TNode* parent = findParent(root, node);
    
    // Node memiliki dua anak
    if (node->left != NULL && node->right != NULL) {
        TNode* successorParent = node;
        TNode* successor = node->right;
        while (successor->left != NULL) {
            successorParent = successor;
            successor = successor->left;
        }
        node->data = successor->data;
        node = successor;
        parent = successorParent;
    }

    // Node memiliki nol atau satu anak
    TNode* child = (node->left != NULL) ? node->left : node->right;

    if (parent == NULL) {
        root = child;
    } else if (parent->left == node) {
        parent->left = child;
    } else {
        parent->right = child;
    }

    delete node;
    cout << "Node berhasil dihapus!" << endl;
}

int main() {
    TNode *root = NULL;

    while (true) {
        cout << "\nMenu:" << endl;
        cout << "1. Tambah Node" << endl;
        cout << "2. Hapus Node" << endl;
        cout << "3. Traversal Pre-Order" << endl;
        cout << "4. Traversal In-Order" << endl;
        cout << "5. Traversal Post-Order" << endl;
        cout << "6. Cetak Anak Node" << endl;
        cout << "7. Cetak Turunan Node" << endl;
        cout << "8. Cari Node" << endl;
        cout << "9. Keluar" << endl;
        cout << "Pilih Menu: ";
        
        int pilihan;
        cin >> pilihan;

        if (pilihan == 1) {
            cout << "Masukkan Nilai Node : ";
            int value;
            cin >> value;

            TNode *node = new TNode(value);

            if (root == NULL) {
                root = node;
            } else {
                int parentValue;
                cout << "Masukkan Node Induk Dari " << value << " : ";
                cin >> parentValue;
                TNode *parent = findNode(root, parentValue);
                if (parent == NULL) {
                    cout << "Node Induk Tidak Dapat Ditemukan!" << endl;
                    delete node;
                } else {
                    if (parent->left == NULL) {
                        parent->left = node;
                    } else if (parent->right == NULL) {
                        parent->right = node;
                    } else {
                        cout << "Node Induk Sudah Memiliki Dua Anak!" << endl;
                        delete node;
                    }
                }
            }

        } else if (pilihan == 2) {
            cout << "Masukkan Nilai Node yang Akan Dihapus : ";
            int value;
            cin >> value;
            deleteNode(root, value);

        } else if (pilihan == 3) {
            cout << "\nTraversal Pre-Order: ";
            preOrder(root);
            cout << endl;

        } else if (pilihan == 4) {
            cout << "\nTraversal In-Order: ";
            inOrder(root);
            cout << endl;

        } else if (pilihan == 5) {
            cout << "\nTraversal Post-Order: ";
            postOrder(root);
            cout << endl;

        } else if (pilihan == 6) {
            cout << "Masukkan Nilai Node: ";
            int value;
            cin >> value;
            printChild(findNode(root, value));

        } else if (pilihan == 7) {
            cout << "Masukkan Nilai Node: ";
            int value;
            cin >> value;
            printDescendant(findNode(root, value));

        } else if (pilihan == 8) {
            cout << "Masukkan Nilai Node: ";
            int value;
            cin >> value;
            TNode* node = findNode(root, value);
            if (node != NULL) {
                cout << "Node Ditemukan: " << node->data << endl;
            } else {
                cout << "Node Tidak Ditemukan" << endl;
            }

        } else if (pilihan == 9) {
            cout << "Keluar dari program." << endl;
            return 0;

        } else {
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    }
}
