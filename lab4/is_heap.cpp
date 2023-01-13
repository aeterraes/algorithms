#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int* a = new int[n + 1];
    a[0] = 0;
    bool flag = true;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
         if ((2 * i <= n) && (a[i] > a[2 * i])) {
             flag = false;
         }
         if ((2 * i + 1 <= n) && (a[i] > a[2 * i + 1])) {
             flag = false;
         }
    }
    if (flag) {
        cout << "YES" << '\n';
    } else {
        cout << "NO" << '\n';
    }
    return 0;
}