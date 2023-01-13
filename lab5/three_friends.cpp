#include <iostream>

using namespace std;

struct node {
    int value;
    string file_name;
    int copy;
    node *left;
    node *right;
    node(int v, string f, int c) {
        value = v;
        file_name = f;
        copy = c;
        left = NULL;
        right = NULL;
    }
};

node* search(node *n, string file) {
    if (n == NULL || n->file_name == file) {
        return n;
    }
    if (file < n->file_name) {
        return search(n->left, file);
    } else {
        return search(n->right, file);
    }
}

void update(node *n) {
    if (n->copy == 0) {
        n->value = 1;
        n->copy++;
    } else if (n->copy == 1) {
        n->value = 0;
        n->copy++;
    }
}

node* insert(node *n, string file) {
    if (n == NULL) {
        return new node(3, file, 0);
    }
    if (n->file_name > file) {
        n->left = insert(n->left, file);
    } else if (n->file_name < file) {
        n->right = insert(n->right, file);
    }
    if (n->file_name == file) update(n);
    return n;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    node *nd = NULL;
    int points[3];
    for (int i = 0; i < 3; i++) {
        points[i] = 0;
    }
    string a[3][n];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            nd = insert(nd, a[i][j]);
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++) {
            node *s = search(nd, a[i][j]);
            points[i] += s->value;
        }
    }
    for (int i = 0; i < 3; i++) {
        cout << points[i] << " ";
    }
    return 0;
}