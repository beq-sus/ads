#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> left(n);
    for(int i = 0; i < n; i++)cin >> left[i];
    int m;
    cin >> m;
    vector<int> right(m);
    for(int i = 0; i < m; i++)cin >> right[i];

    vector<int> res;
    int i = 0, j = 0;

    while(i < n && j < m){
        if(left[i] <= right[j]){
            res.push_back(left[i]);
            i++;
        } else {
            res.push_back(right[j]);
            j++;
        }
    }

    while(i < n){
        res.push_back(left[i]);
        i++;
    }

    while(j < m){
        res.push_back(right[j]);
        j++;
    }

    for(int i : res)cout << i << " ";

    return 0;
}