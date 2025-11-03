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
    string pass, s;
    int k;
    cin >> pass >> k >> s;


    vector<int> lps = LPS(pass);
    int n = s.size();
    int m = pass.size();
    int i = 0, j = 0;
    int cnt = 0;

    while(i < n){
        if(pass[j] == s[i]){
            i++;
            j++;
            
            if(j == m){
                cnt++;
                j = lps[j - 1];
            }
        } else {
            if(j != 0){
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }

    if(cnt >= k)cout << "YES";
    else cout << "NO";
    
}