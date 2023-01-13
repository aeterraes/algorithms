#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int left(int i) {
    return 2 * i + 1;
}

int right(int i){
    return 2 * i + 2;
}

int parent(int i) {
    return (i - 1) / 2;
}

void sift_down(vector<pair<int, int>>& a, int i) {
    int n = a.size();
    int mx = i;
    int l = left(i);
    int r = right(i);
    if (l < n && (a[l].first < a[i].first)) {
        mx = l;
    }
    if (r < n && (a[r].first < a[mx].first)) {
        mx = r;
    }
    if (mx != i) {
        swap(a[i], a[mx]);
        sift_down(a, mx);
    }
}

void sift_up(vector <pair<int, int>>& a, int i) {
    while (i > 0 && (a[i].first < a[parent(i)].first)) {
        swap(a[parent(i)], a[i]);
        i = parent(i);
    }
}

int extract_min(vector<pair<int, int>>& a) {
    int n = a.size();
    int mn = a[0].first;
    a[0] = a[n - 1];
    a.pop_back();
    sift_down(a, 0);
    return mn;
}

void push(vector<pair<int, int>>& a, int value, int num) {
    int n = a.size();
    a.emplace_back(value, num);
    sift_up(a, n );
}

void decrease_key(vector<pair<int, int>>& a, int num, int value) {
    int n = a.size();
    int tmp;
    for (int i = 0; i < n; i++) {
        if (a[i].second == num) {
            tmp = i;
        }
    }
    a[tmp].first = value;
    sift_up(a, tmp);
}

bool is_empty_queue(vector<pair<int, int>>& a) {
    if (a.size() == 0) {
        return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<pair<int, int>> a;
    string st;
    int cnt = 1;
    while(getline(cin, st)) {
        if (st.empty()) {
            break;
        }
        stringstream s(st);
        string comm;
        s >> comm;
        if (comm == "push") {
            int x;
            s >> x;
            push(a, x, cnt);
        }
        if (comm == "extract-min") {
            if (is_empty_queue(a)) {
                cout << '*' << '\n';
            } else {
                int m = extract_min(a);
                cout << m << '\n';
            }
        }
        if (comm == "decrease-key") {
            int x, y;
            s >> x >> y;
            decrease_key(a, x, y);
        }
        cnt++;
    }
    return 0;
}