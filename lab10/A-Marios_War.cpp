#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n + 2, vector<int>(m + 2, 0));


    int mush = 0;
    queue<pair<int, int>> q;
    for(int i = 0; i < n + 2; i++){
        for(int j = 0; j < m + 2; j++){
            if(i == 0 || j == 0 || i == n + 1 || j == m + 1){
                v[i][j] = 3;
                continue;
            }
            cin >> v[i][j];
            if(v[i][j] == 2){
                q.push({i, j});
            } else if(v[i][j] == 1){
                mush++;
            }
        }
    }

    int cnt = 0;
    while(!q.empty()){
        if(!mush)break;

        int size = q.size();
        while(size--){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            if(v[i][j+1] == 1){
                v[i][j+1] = 2;
                q.push({i, j+1});
                mush--;
            }
            if(v[i][j-1] == 1){
                v[i][j-1] = 2;
                q.push({i, j-1});
                mush--;
            }
            if(v[i+1][j] == 1){
                v[i+1][j] = 2;
                q.push({i+1, j});
                mush--;
            }
            if(v[i-1][j] == 1){
                v[i-1][j] = 2;
                q.push({i-1, j});
                mush--;
            }
        }
        cnt++;
    }

    if(!mush)cout << cnt;
    else cout << -1;

    return 0;
}