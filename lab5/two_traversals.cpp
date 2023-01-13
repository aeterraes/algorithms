#include <iostream>
#include <vector>

using namespace std;

vector<int> num;

void traverse(int a[], int n, int mx, int mn, int& pos) {
    if (pos == n) return;
    if (a[pos] < mn || a[pos] > mx) return;
    int p = a[pos];
    pos++;
    traverse(a, n, p, mn, pos);
    traverse(a, n, mx, p, pos);
    num.push_back(p);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int mx = 200001;
    int mn = 0;
    int pos = 0;
    traverse(a, n, mx, mn, pos);
    for (int i = 0; i < num.size(); i++) {
        cout << num[i] << " ";
    }
    return 0;
}