#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<string> v(n);

    for(int i = 0; i < n; i++)cin >> v[i];

    string shortest = v[0];
    for(int i = 1; i < n; i++){
        if(v[i].size() < shortest.size()){
            shortest = v[i];
        }
    }

    string res = "";
    int max_size = 0;

    int k = shortest.size();

    for(int i = 0; i < k; i++){
        for(int j = i; j < k; j++){
            string sub = shortest.substr(i, j - i + 1);

            bool flag = true;
            for(string s : v){
                if(s.find(sub) == string::npos){
                    flag = false;
                    break;
                }
            }

            if(flag && sub.size() > max_size){
                res = sub;
                max_size = sub.size();
            }
        }
    }

    cout << res;

    return 0;
}