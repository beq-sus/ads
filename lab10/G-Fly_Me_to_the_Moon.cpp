#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> v(501);
vector<int> used(501, 0);

void dfs(int x, bool &flag, int a, int b){
    used[x] = 1;

    for(int i : v[x]){
        if(x == a && i == b)continue;
        else if(!used[i])dfs(i, flag, a, b);
        else if(used[i] == 1){
            flag = false;
            return;
        }
    }
    used[x] = 2;
}

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
    }

    bool flag;
    
    for (int i = 1; i <= n; i++)
    {
        for (int j : v[i])
        {
            int a = i;
            int b = j;
            flag = true;
            fill(used.begin(), used.end(), 0);

            for (int start = 1; start <= n && flag; start++)
            {
                if (used[start] == 0)
                    dfs(start, flag, a, b);
            }

            if (flag)
            {
                cout << "YES";
                return 0;
            }
        }
    }
    cout << "NO";


    

    return 0;
}