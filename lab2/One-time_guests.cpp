#include <bits/stdc++.h>
 
using namespace std;


int main(){
    int n;
    cin >> n;

    while(n--){
        int k;
        cin >> k;

        queue<char> que;
        vector<int> cnt(26, 0);

        while(k--){
            char ch;
            cin >> ch;
            que.push(ch);
            cnt[ch - 'a']++;

            while(!que.empty() && cnt[que.front() - 'a'] > 1)que.pop();

            if(que.empty()) cout << -1 << " ";
            else cout << que.front() << " ";
        }
        cout << endl;
    }

    return 0;
}