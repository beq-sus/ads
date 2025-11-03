#include <bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin >> n;
    vector<long long> v(n);

    for(int i = 0; i < n; i++)cin >> v[i];

    string res;
    res += 97 + v[0];
    long long power = 2;

    for(int i = 1; i < n; i++){
        res += char(97 + (v[i] - v[i - 1]) / power);
        power = power * 2;
    }

    cout << res;

    return 0;
}