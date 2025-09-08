#include <bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin >> n;
    
    map<int, int> mp;

    for(int i = 0; i < n; i++){
        int k;
        cin >> k;
        mp[k]++;
    }
    int mode = 0;
    int maxn = 0;

    for(pair<int, int> i : mp){
        if(i.second > maxn){
            maxn = i.second;
        }
    }

    map <int, int> :: reverse_iterator it;
    for(it = mp.rbegin(); it != mp.rend(); it++){
        if(maxn == it->second){
            cout << it->first << ' ';
        }
    }

    

    return 0;
}