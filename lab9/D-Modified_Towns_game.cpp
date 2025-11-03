#include <bits/stdc++.h>
using namespace std;

vector<int> LPS(string pattern) {
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
    string prev;
    int n;
    cin >> prev >> n;


    int best = 0;
    vector<int> buf(n);
    vector<string> variants(n);
    for(int i = 0; i < n; i++){
        cin >> variants[i];
        variants[i][0] = tolower(variants[i][0]);
        
        vector<int> lps = LPS(variants[i] + prev);
        int overlap = lps.back();
        // for(int i : lps)cout << i << " ";
        // cout << endl;
        if(overlap > best)best = overlap;
        buf[i] = overlap;
    }
    // cout << best;
    // for(int i : buf) cout << i << " ";

    vector<string> res;

    for (int i = 0; i < n; i++) {
        variants[i][0] = toupper(variants[i][0]);
        
        if(buf[i] == best && best != 0){
            res.push_back(variants[i]);
        }
    }

    cout << res.size() << endl;
    for(string i : res)cout << i << endl;

    return 0;
}