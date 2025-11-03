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
    string tamer, alik;
    cin >> tamer >> alik;
    alik += alik;

    int n = alik.size();
    int m = tamer.size();
    vector<int> lps = LPS(tamer);
    int i = 0, j = 0;

    while(i < n){
        if(alik[i] == tamer[j]){
            i++;
            j++;
            if(j == m){
                cout << i - j;
                return 0;
            }
        } else {
            if(j != 0)j = lps[j - 1];
            else i++;
        }
    }

    cout << -1;
    return 0;
}