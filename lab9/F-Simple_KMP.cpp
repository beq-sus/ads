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
    string s1, s2;
    cin >> s1 >> s2;
    vector<int> res;

    if(s1.size() < s2.size()){
        string temp = s1;
        s1 = s2;
        s2 = temp;
    }

    vector<int> lps = LPS(s2);
    int n = s1.size();
    int m = s2.size();
    int i = 0, j = 0;

    while(i < n){
        if(s1[i] == s2[j]){
            i++;
            j++;
            if(j == m){
                res.push_back(i - j);
                j = lps[j-1];
            }
        } else {
            if(j != 0)j = lps[j-1];
            else i++;
        }
    }

    cout << res.size()<< endl;
    for(int i : res) cout << i+1 << " ";  
    



    return 0;
}