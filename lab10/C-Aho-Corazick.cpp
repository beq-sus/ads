#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b;
    cin >> a >> b;

    vector<int> used(10001, 0), v(10001, -1);
    
    queue<int> q;
    q.push(a);
    used[a] = 1;
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        if(curr * 2 <= 10001 && !used[curr * 2]){
            q.push(curr * 2);
            v[curr * 2] = curr;
            used[curr * 2] = used[curr] + 1;
        }
        if(curr - 1 > 0 && !used[curr - 1]){
            q.push(curr - 1);
            v[curr - 1] = curr;
            used[curr - 1] = used[curr] + 1;
        }
    }

    cout << used[b] - 1 << endl;
    vector<int> res;
    while(v[b] != -1){
        res.push_back(b);
        b = v[b];
    }
    for(int i = res.size() - 1; i >= 0; i--){
        cout << res[i] << " ";
    }


    return 0;
}