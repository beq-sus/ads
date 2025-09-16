#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, h;
    cin >> n >> h;

    vector<long> v(n);
    for(int i = 0; i < n; i++)cin >> v[i];

    long l = 1;
    long r = 0;
    for(long i : v){
        r = max(r, i);
    }
    while(l < r){
        long m = (l + r) / 2;
        
        long cnt = 0;
        for(long i : v){
            cnt += (i + m - 1) / m;
        }

        if(cnt <= h)r = m;
        else l = m + 1;
    }
    cout << l;

}