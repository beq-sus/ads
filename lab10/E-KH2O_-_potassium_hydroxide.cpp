#include <bits/stdc++.h>
using namespace std;


int main(){
    int n, k;
    cin >> n >> k;
    vector<vector<int>> v(n, vector<int>(n, 0));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> v[i][j];
        }
    }

    while(k--){
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        c--;
        if(v[a][b] && v[b][c] && v[a][c]){
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }

    return 0;
}