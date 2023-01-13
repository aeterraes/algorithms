#include <iostream>

using namespace std;

struct node {
    int v;
    int l;
    int r;
};

struct node* nd;
bool ok = true;

void is_bst(node *nd, int root, int mx, int mn) {
    if (nd[root].v <= mn || nd[root].v >= mx) {
        ok = false;
    }
    if (nd[root].l > 0) {is_bst(nd, nd[root].l, nd[root].v, mn);}
    if (nd[root].r > 0) {is_bst(nd, nd[root].r, mx, nd[root].v);}
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    if (n == 0) {
        cout << "YES" << '\n';
        return 0;
    }
    nd = new struct node[n];
    for (int i = 0; i < n; i++) {
        cin >> nd[i].v >> nd[i].l >> nd[i].r;
        nd[i].l -= 1;
        nd[i].r -= 1;
    }
    is_bst(nd, 0, 1000000001,-1000000001);
    if (ok) {
        cout << "YES" << '\n';
    } else {
        cout << "NO" << '\n';
    }
    return 0;
}