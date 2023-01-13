#include <iostream>
#include <vector>

bool ok(long long m, const int* a, int n, int k) {
    long long cur_sum = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > m) {
            return false;
        }
        cur_sum += a[i];
        if (cur_sum > m) {
            cnt++;
            cur_sum = a[i];
        }
    }
    cnt++;
    if (cnt <= k) {
        return true;
    }
    return false;
}

long long find_sum (const int* a, long long l, long long r, int n, int k) {
    while (l < r) {
        long long m = (l + r) / 2;
        if (ok(m, a, n, k)) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    return l;
}

std::vector<int> get_nums(long long s, const int* a, int n, int k) {
    std::vector<int> nums;
    nums.resize(k  - 1);
    long long cur_sum = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (cur_sum + a[i] > s) {
            cur_sum = a[i];
            nums[cnt] =  i;
            cnt++;
        } else {
            cur_sum += a[i];
        }
    }
    int start = 0;
    int it = 1;
    int last = k - 2;
    while (nums[last] == 0) {
        if (it != nums[start]) {
            nums[last] = it;
            last--;
        }
        it++;
        if (it > nums[start]) {
            start++;
        }
    }
    std::sort(nums.begin(), nums.end());
    return nums;
}

int get_mx(const int* a, int n, int mx) {
    for (int i = 0; i < n; i++) {
        if (a[i] > mx) {
            mx = a[i];
        }
    }
    return mx;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n, k;
    long long arr_sum = 0;
    std::cin >> n >> k;
    int* a = new int[n];
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        arr_sum += a[i];
    }
    int mx = get_mx(a, n, a[0]);
    long long s = find_sum(a, mx, arr_sum, n, k);
    std::vector<int> nums = get_nums(s, a, n, k);
    for (auto i : nums) {
        std::cout << i << ' ';
    }
    return 0;
}