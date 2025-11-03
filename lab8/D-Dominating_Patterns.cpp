#include <bits/stdc++.h>
using namespace std;

class RabinKarpHash {
private:
    const int mod = 1e9 + 7;
    const int base = 31;
    vector<int> hash;
    vector<int> power;

    int add(int a, int b) {
        a += b;
        if (a >= mod) a -= mod;
        return a;
    }

    int sub(int a, int b) {
        a -= b;
        if (a < 0) a += mod;
        return a;
    }

    int mul(int a, int b) {
        return (int)((1LL * a * b) % mod);
    }

    int charToInt(char c) {
        return c - 'a' + 1;
    }

public:
    RabinKarpHash(string &s) {
        int n = s.size();
        hash.resize(n);
        power.resize(n);

        hash[0] = charToInt(s[0]);
        power[0] = 1;

        for (int i = 1; i < n; ++i) {
            hash[i] = add(mul(hash[i - 1], base), charToInt(s[i]));
            power[i] = mul(power[i - 1], base);
        }
    }

    int getSubHash(int l, int r) {
        int h = hash[r];
        if (l > 0) {
            h = sub(h, mul(hash[l - 1], power[r - l + 1]));
        }
        return h;
    }
};

int main(){
    int n;
    cin >> n;
    while(n){
        vector<string> v(n);
        for(int i = 0; i < n; i++)cin >> v[i];
        string s;
        cin >> s;

        RabinKarpHash Ss(s);
        vector<pair<string, int>> mp(n);
        int cnt = 0;
        for(int i = 0; i < n; i++){
            RabinKarpHash H(v[i]);
            int t = v[i].size();
            int hash_t = H.getSubHash(0, t - 1);
            mp[i].first = v[i];
            
            for(int j = 0; j + t <= s.size(); j++){
                if(hash_t == Ss.getSubHash(j, t + j - 1)){
                    mp[i].second++;
                    cnt = max(cnt, mp[i].second);
                }
            }

            
        }
        cout << cnt << endl;
        for(pair<string, int> j : mp){
            if(j.second == cnt)cout << j.first << endl;
        }

        cin >> n;
    }
    

    return 0;
}