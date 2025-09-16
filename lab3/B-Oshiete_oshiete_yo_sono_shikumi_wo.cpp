#include <bits/stdc++.h>
using namespace std;

bool suka(const vector<long long>& a, int k, long long X){
    int block = 1;
    long long sum = 0;

    for(long long i : a){
        if(sum + i > X){
            block++;
            sum = i;
        } else { 
            sum += i;
        }
    }

    return block <= k;
}


int main(){
    int n, k;
    cin >> n >> k;
    vector<long long> v(n);

    long long r = 0, l = 0;

    for(int i = 0; i < n; i++){
        cin >> v[i];
        l = max(l, v[i]);
        r += v[i];
    }

    while(l < r){
        long long m = (l + r) / 2;

        if(suka(v, k, m)){
            r = m;
        } else {
            l = m + 1;
        }
    }
    cout << l;

    return 0;
}