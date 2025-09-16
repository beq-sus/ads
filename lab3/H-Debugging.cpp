#include <bits/stdc++.h>
using namespace std;

int bsearch(const vector<int>& v, int target){
    int l = 0;
    int r = v.size() - 1;
    int res = v.size();
    while(l <= r){
        int m = (l + r) / 2;
        if(v[m] >= target){
            r = m - 1;
            res = m;
        } else {
            l = m + 1;
        }
    }
    return res;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> lines(n);
    int cnt = 0;
    for(int i = 0; i < n; i++){
        int k;
        cin >> k;
        lines[i] = k + cnt;
        cnt += k;
    }
    vector<int> mis(m);
    for(int i = 0; i < m; i++)cin >> mis[i];
    for(int i : mis)cout << bsearch(lines, i) + 1 << endl;
    return 0;
}