#include <bits/stdc++.h>
using namespace std;

vector<int> LPS(string &pattern) {
    int n = pattern.size();
    vector<int> lps(n, 0);

    int len = 0;  
    int i = 1;

    while (i < n) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) { 
                len = lps[len - 1];  
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}

int main(){
    string s;
    cin >> s;

    int n = s.size();
    vector<int> lps = LPS(s);

    // for(int i : lps)cout << i << " ";

    int cnt = 0;
    for(int i = 1; i < n; i++){
        if(i % 2 == 0){
            if((i / (i - lps[i - 1])) % 2 == 0)cnt++;
        }
    }

    cout << cnt;

    return 0;
}