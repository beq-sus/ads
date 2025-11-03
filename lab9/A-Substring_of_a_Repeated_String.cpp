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

bool isSub(string a, string b, int x){
    string pat = "";
    while(x--){
        pat += a;
    }
    vector<int> lps = LPS(b);
    int n = pat.size();
    int m = b.size();

    int i = 0, j = 0;
    while(i < n){
        if(pat[i] == b[j]){
            i++;
            j++;
            if(j == m){
                return true;
            }
        } else {
            if(j != 0){
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    return false;
}

int main(){
    string A, B;
    cin >> A >> B;
    
    string pat = "";
    int r = (B.size() * 2 + A.size() - 1) / A.size();
    int l = 1;

    vector<int> lps = LPS(B);

    while(l < r){
        int m = (l + r) / 2;
        
        if(isSub(A, B, m))r = m;
        else l = m + 1;
    }

    
    if(isSub(A, B, l))cout << l;
    else cout << -1;

    

    return 0;
}
