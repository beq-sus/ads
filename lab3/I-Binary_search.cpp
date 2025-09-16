#include <bits/stdc++.h>
using namespace std;

bool bsearch(const vector<int>& v, int target){
    int l = 0;
    int r = v.size() - 1;
    while(l <= r){
        int m = (l + r) / 2;
        if(v[m] == target){
            return true;
        } else if(v[m] > target) {
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    return false;
}

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)cin >> v[i];
    int k;
    cin >> k;

    cout << (bsearch(v, k) ? "Yes" : "No");
}