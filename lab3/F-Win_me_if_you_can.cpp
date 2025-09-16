#include <bits/stdc++.h>
using namespace std;

int most_right(const vector<int>& v, long long target) {
    int l = 0, r = v.size();
    while (l < r) {
        int m = (l + r) / 2;
        if (v[m] <= target) l = m + 1;
        else r = m;
    }
    return l;
}


int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)cin >> v[i];
    sort(v.begin(), v.end());

    int p;
    cin >> p;
    while(p--){
        int k;
        cin >> k;
        int sum = 0;
        int cnt = most_right(v, k);     
        cout << cnt << " ";
        for(int i = 0; i < cnt; i++)sum += v[i];
        cout << sum << endl;
    }
    return 0;
}