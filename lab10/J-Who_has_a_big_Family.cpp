#include <bits/stdc++.h>
using namespace std;


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

    vector<int> used(n + 1, 0);
    vector<int> counter(n+1, 0);

    for(int i = 1; i <= n; i++){
        if(!used[i]){
            queue<int> q;
            q.push(i);
            used[i] = i;

            while(!q.empty()){
                int curr = q.front();
                q.pop();

                for(int x : v[curr]){
                    if(!used[x]){
                        counter[curr]++;
                        used[x] = curr;
                        q.push(x);
                    }
                }
            }
        }
    }

    // for(int i : used)cout << i << " ";
    // cout << endl;
    // for(int i : counter)cout << i << " ";
    // cout << endl;

    // for(vector<int> i : v){
    //     for(int j : i){
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }

    int cnt = 0;

    for(int i = 1; i <= n; i++){
        if(used[i] != i){
            if(counter[i] > counter[used[i]]){
                cnt++;
            }
        } else cnt++;
    }

    cout << cnt;



    


    return 0;
}