#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    string s;
    cin >> s;

    queue<int> K, S;

    for(int i = 0; i < n; i++){
        if(s[i] == 'K')K.push(i);
        else S.push(i);
    }

    while(!K.empty() && !S.empty()){
        int idxk = K.front();
        int idxs = S.front();

        K.pop();
        S.pop();

        if(idxk > idxs){
            S.push(n + idxk);
        }
        else {
            K.push(n + idxs);
        }
    }
    
    cout << (K.empty() ? "SAKAYANAGI" : "KATSURAGI");


    return 0;
}