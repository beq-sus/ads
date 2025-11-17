#include <bits/stdc++.h>
using namespace std;

vector<int> used(5001, 5001);

void bfs(vector<vector<int>> &v, int b){
    queue<int> q;
    q.push(b);
    used[b] = 0;

    while(!q.empty()){
        int curr = q.front();
        q.pop();

        for(int i = 0; i < v[curr].size(); i++){
            if(used[curr] + 1 < used[v[curr][i]]){
                used[v[curr][i]] = used[curr] + 1;
                q.push(v[curr][i]);
            }
        }
    }
}


int main(){
    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<int>> v(n+1);

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    while(q--){
        int a, b;
        cin >> a >> b;
        
        if(a == 1){
            bfs(v, b);
        }else{
            cout << (used[b] == 5001 ? -1 : used[b]) << endl;
        }
    }
    


    return 0;
}