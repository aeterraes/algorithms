#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

struct node {
    int value;
    node *left;
    node *right;
    node(int v) {
        value = v;
        left = NULL;
        right = NULL;
    }
};

node* minimum(node *n) {
    if (n->left == NULL) {
        return n;
    }
    return minimum(n->left);
}

node* maximum(node *n){
    if (n->right == NULL) {
        return n;
    }
    return maximum(n->right);
}

node* insert(node *n, int key) {
    if (n == NULL) {
        return new node(key);
    }
    if (n->value > key) {
        n->left = insert(n->left, key);
    } else if (n->value < key) {
        n->right = insert(n->right, key);
    }
    return n;
}

node* delete_b(node *n, int key) {
    if (n == NULL) {
        return NULL;
    }
    if (key < n->value) {
        n->left = delete_b(n->left, key);
    } else if (key > n->value) {
        n->right = delete_b(n->right, key);
    } else if (n->left != NULL && n->right != NULL){
        n->value = (minimum(n->right))->value;
        n->right = delete_b(n->right, n->value);
    } else {
        if (n->left != NULL) {
            n = n->left;
        } else if (n->right != NULL) {
            n = n->right;
        } else {
            n = NULL;
        }
    }
    return n;
}

node* search(node *n, int key) {
    if (n == NULL || key == n->value) {
        return n;
    }
    if (key < n->value) {
        return search(n->left, key);
    } else {
        return search(n->right, key);
    }
}

node* next(node *n, int key) {
    node *cur = n;
    node *s = NULL;
    while (cur != NULL) {
        if (cur->value > key) {
            s = cur;
            cur = cur->left;
        } else {
            cur = cur->right;
        }
    }
    return s;
}

node* prev(node *n, int key) {
    node *cur = n;
    node *s = NULL;
    while (cur != NULL) {
        if (cur->value < key) {
            s = cur;
            cur = cur->right;
        } else {
            cur = cur->left;
        }
    }
    return s;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    node *n = NULL;
    string st;
    while(getline(cin, st)) {
        if (st.empty()) {
            break;
        }
        stringstream s(st);
        string comm;
        s >> comm;
        if (comm == "insert") {
            int x;
            s >> x;
            n = insert(n, x);
        }
        if (comm == "delete") {
            int x;
            s >> x;
            n = delete_b(n, x);
        }
        if (comm == "exists") {
            int x;
            s >> x;
            if (search(n, x)) {
                cout << "true" << '\n';
            } else {
                cout << "false" << '\n';
            }
        }
        if (comm == "next") {
            int x;
            s >> x;
            node *nxt = next(n, x);
            if (nxt != NULL) {
                cout << nxt->value << '\n';
            } else {
                cout << "none" << '\n';
            }
        }
        if (comm == "prev") {
            int x;
            s >> x;
            node *prv = prev(n, x);
            if (prv != NULL) {
                cout << prv->value << '\n';
            } else {
                cout << "none" << '\n';
            }
        }
    }
    return 0;
}