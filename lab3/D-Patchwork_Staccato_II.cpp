#include <bits/stdc++.h>
using namespace std;

int find_left(const vector<long long>& v, long long target) {
    int l = 0, r = v.size();
    while (l < r) {
        int m = (l + r) / 2;
        if (v[m] < target) l = m + 1;
        else r = m;
    }
    return l;
}

int find_right(const vector<long long>& v, long long target) {
    int l = 0, r = v.size();
    while (l < r) {
        int m = (l + r) / 2;
        if (v[m] <= target) l = m + 1;
        else r = m;
    }
    return l;
}

int cnt(const vector<long long>& v, long long L, long long R) {
    if (L > R) return 0;
    int left_idx = find_left(v, L);
    int right_idx = find_right(v, R);
    return right_idx - left_idx;
}

int main() {
    int n, q;
    cin >> n >> q;
    vector<long long> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());

    while (q--) {
        long long l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;

        int c1 = cnt(v, l1, r1);
        int c2 = cnt(v, l2, r2);
        int over = cnt(v, max(l1, l2), min(r1, r2));
        cout << c1 + c2 - over << "\n";
    }
    return 0;
}
