#include <bits/stdc++.h>
using namespace std;


int main(){
    int n, q;
    cin >> n >> q;
    vector<long long> v(n);

    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    vector<long long> g(4);
    for(int i = 0; i < q; i++){
        cin >> g[0] >> g[1] >> g[2] >> g[3];
        int cnt = 0;

        for(int j : v){
            if(g[0] <= j && j <= g[1] || g[2] <= j && j <= g[3])cnt++;
        }

        cout << cnt << endl;

    }



    return 0;
}