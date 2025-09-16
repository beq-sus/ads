#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, f; 
    cin >> n >> f;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    
    int l = 1;
    int r = 0;
    for(int i : v){
        r = max(r, i);
    }

    while(l < r){
        int m = (l + r) / 2;

        int cnt = 0;
        for(int i : v){
            cnt += (i + m - 1) / m;
        }

        if(cnt <= f) r = m;
        else l = m + 1;
    }
    cout << l;
    
    
    return 0;
}