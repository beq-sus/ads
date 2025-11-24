#include <bits/stdc++.h>
using namespace std;

vector<int> p;

int dsu_find(int i)
{
    if (i == p[i])
    {
        return i;
    }
    return p[i] = dsu_find(p[i]);
}

bool dsu_unit(int a, int b){
    a = dsu_find(a);
    b = dsu_find(b);

    if(a != b){
        p[b] = a;
        return true;
    }

    return false;
}

int main(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> v(n);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for(int i = 0; i < n; i++)p.push_back(i);

    vector<int> res;
    int cnt = 0;

    for(int i = n-1; i >= 0; i--){
        res.push_back(cnt);
        cnt++;
        for(int j : v[i]){
            if(j > i && dsu_unit(i, j)){
                cnt--;
            }
        }
    }

    for(int i = n-1; i >= 0; i--){
        cout << res[i] << endl;
    }

    




    return 0;
}