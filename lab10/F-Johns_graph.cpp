#include <bits/stdc++.h>
using namespace std;

vector<bool> used(100001, 0);

void dfs(vector<vector<int>> &graph, int s, vector<int> &comp){

    used[s] = 1;
    comp.push_back(s);
    for(int i = 0; i < graph[s].size(); i++){
        int lec = graph[s][i];
        if(!used[lec]){
            dfs(graph, lec, comp);
        }
    }


}

int main(){
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> v(n+1);

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    vector<int> comp;



    int s, f;
    cin >> s >> f;

    dfs(v, s, comp);

    for(int i : comp){
        if(i == f){
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";

    return 0;
}