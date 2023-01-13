#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    if (n == 0) {
        cout << "0" << '\n';
        return 0;
    } else {
        int a[n][3];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 3; j++) {
                cin >> a[i][j];
            }
        }
        int h[n];
        int height = 0;
        for (int i = 0; i < n; i++) {
            h[i] = 0;
        }
        for (int i = 0; i < n; i++) {
            if (a[i][1] > 0) {
                h[a[i][1] - 1] = h[i] + 1;
                height = max(height, h[a[i][1] - 1]);
            }
            if (a[i][2] > 0) {
                h[a[i][2] - 1] = h[i] + 1;
                height = max(height, h[a[i][2] - 1]);
            }
        }
        cout << height + 1 << '\n';
    }
    return 0;
}