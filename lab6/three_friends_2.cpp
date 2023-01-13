#include <iostream>

using namespace std;

struct node {
  int value;
  string file_name;
  int copy;
  int h;
  node *left;
  node *right;
  node(int v, string f, int c) {
    value = v;
    file_name = f;
    copy = c;
    h = 1;
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

int height(node *n) {
  if (n == NULL) {
    return 0;
  }
  return n->h;
}

int balance(node *n) {
  if (n == NULL) {
    return 0;
  }
  return height(n->left) - height(n->right);
}

node* left_rotation(node *n) {
  node *one = n->right;
  node *two = one->left;
  one->left = n;
  n->right = two;
  n->h = max(height(n->left), height(n->right)) + 1;
  one->h = max(height(one->left), height(one->right)) + 1;
  return one;
}

node* right_rotation(node *n) {
  node *one = n->left;
  node *two = one->right;
  one->right = n;
  n->left = two;
  n->h = max(height(n->left), height(n->right)) + 1;
  one->h = max(height(one->left), height(one->right)) + 1;
  return one;
}

node* insert(node *n, string file) {
  if (n == NULL) {
    return new node(3, file, 0);
  }
  if (n->file_name > file) {
    n->left = insert(n->left, file);

  } else if (n->file_name < file) {
    n->right = insert(n->right, file);
  } else {
    update(n);
    return n;
  }
  n->h = max(height(n->left), height(n->right)) + 1;
  int b = balance(n);
  if (b > 1) {
    if (file < n->left->file_name) {
      return right_rotation(n);
    } else {
      n->left = left_rotation(n->left);
      return right_rotation(n);
    }
  }
  if (b < -1) {
    if (file > n->right->file_name) {
      return left_rotation(n);
    } else {
      n->right = right_rotation(n->right);
      return left_rotation(n);
    }
  }
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