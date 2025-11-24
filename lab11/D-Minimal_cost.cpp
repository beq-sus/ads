#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<vector<int>> v(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> v[i][j];
        }
    }

    vector<bool> used(n, false);
    int cnt = 0;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, 0}); 

    while(!pq.empty()){
        int curr = pq.top().second;
        int wt = pq.top().first;
        pq.pop();
        
        if(used[curr])continue;
        
        cnt += wt;
        used[curr] = true;
        
        for(int i = 0; i < n; i++){
            if(!used[i]){
                pq.push({v[curr][i], i});
            }
        }

    }
    cout << cnt;


    return 0;
}