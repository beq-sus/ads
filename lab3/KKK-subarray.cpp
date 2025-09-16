#include <bits/stdc++.h>
using namespace std;

int main(){
    long n, k;
    cin >> n >> k;

    vector<long> v(n), pref(n+1, 0);
    for(int i = 0; i < n; i++){
        cin >> v[i];
        pref[i+1] = pref[i] + v[i];
    }

    int min_size = INT_MAX;

    for(int i = 0; i < n + 1; i++){
        int l = i + 1;
        int r = n;

        while(l <= r){
            int m = (l + r) / 2;

            if(pref[m] - pref[i] >= k) r = m - 1;
            else l = m + 1;
        }
        if(l <= n && pref[l] - pref[i] >= k)
            min_size = min(min_size, l - i);

        
    }
    cout << min_size;
    return 0;
}