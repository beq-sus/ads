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

    int start, end;
    cin >> start >> end;

    start--;
    end--;

    vector<int> mark(n, 0);
    queue<int> q;
    
    q.push(start);

    while(!q.empty()){
        int curr = q.front();
        q.pop();

        for(int i = 0; i < n; i++){
            if(v[curr][i] == 1 && !mark[i]){
                mark[i] = mark[curr] + 1;
                q.push(i);
            }
        }
    }

    cout << (mark[end] ? mark[end] : -1);

    return 0;
}