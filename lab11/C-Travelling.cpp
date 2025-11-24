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

void dsu_unit(int a, int b){
    a = dsu_find(a);
    b = dsu_find(b);

    if(a != b){
        p[b] = a;
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    int x, y;
    cin >> x >> y;
    int small = min(x, y);

    vector<pair<int, pair<int,int>>> v;

    while(m--){
        string s;
        int a, b, c;
        cin >> s >> a >> b >> c;
        a--;
        b--;
        if(s == "both"){
            c = small * c;
        } else if(s == "big") {
            c = x * c;
        } else {
            c = y * c;
        }
        v.push_back({c, {a, b}});
    }

    for(int i = 0; i < n; i++){
        p.push_back(i);
    }
    sort(v.begin(), v.end());

    int cnt = 0;
    for(int i = 0; i < v.size(); i++){
        int l = v[i].second.first;
        int r = v[i].second.second;
        int w = v[i].first;
        // cout << w << " ";
        
        if(dsu_find(l) != dsu_find(r)){
            cnt += w;
            dsu_unit(l, r);
        }
    }
    cout << cnt;

    return 0;
}