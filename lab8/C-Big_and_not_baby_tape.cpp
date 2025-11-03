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
    string s;
    cin >> s;
    int n;
    cin >> n;
    vector<string> v(n);
    for(int i = 0; i < n; i++)cin >> v[i];

    int t = s.size();
    vector<int> covered(t, 0);

    RabinKarpHash hash(s);

    for(string i : v){
        RabinKarpHash h(i);
        int m = i.size();
        int hash_t = h.getSubHash(0, m - 1);

        for(int j = 0; j + m <= t; j++){
            if(hash.getSubHash(j, j + m - 1) == hash_t){
                for(int k = j; k < j + m; k++)covered[k] = 1;
            }
        }
    }
    for(int i : covered){
        if(!i){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";



    return 0;
}   