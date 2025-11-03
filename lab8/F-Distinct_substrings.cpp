#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    int n = s.size();
    long long base1 = 911382323;
    long long base2 = 972663749;
    long long mod1 = 1e9 + 7;
    long long mod2 = 1e9 + 9;

    set<pair<long long, long long>> hashes;

    for(int i = 0; i < n; i++){
        long long hash1 = 0, hash2 = 0;


        for(int j = i; j < n; j++){
            hash1 = (hash1 * base1 + (s[j] - 'a' + 1)) % mod1;
            hash2 = (hash2 * base2 + (s[j] - 'a' + 1)) % mod2;

            hashes.insert(make_pair(hash1, hash2));
        }
    }

    cout << hashes.size();

    return 0;
}