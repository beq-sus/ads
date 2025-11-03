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
    string s1, s2, p;
    cin >> s1 >> s2 >> p;
    
    int n1 = s1.size();
    int n2 = s2.size();
    int t = p.size();

    RabinKarpHash h1(s1);
    RabinKarpHash h2(s2);
    RabinKarpHash h3(p);

    int hash_p = h3.getSubHash(0, t-1);
    
    vector<bool> match1(n1, false), match2(n2, false);

    for(int i = 0; i + t <= n1; i++){
        int subhash = h1.getSubHash(i, i + t - 1);
        if(subhash == hash_p) match1[i] = true;
    }
    for(int i = 0; i + t <= n2; i++){
        int subhash = h2.getSubHash(i, i + t - 1);
        if(subhash == hash_p) match2[i] = true;
    }

    int cnt = 0;
    int n = min(n1, n2);
    for(int i = 0; i < n; i++){
        if(match1[i] && match2[i])cnt++;
    }

    cout << cnt;
    
    

    return 0;
}