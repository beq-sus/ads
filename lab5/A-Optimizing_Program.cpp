#include <bits/stdc++.h>
#include <queue>
using namespace std;

int main(){
    priority_queue<long long, vector<long long>, greater<long long>> pq;

    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        long long num;
        cin >> num;
        pq.push(num);
    }

    long long res = 0;

    while(pq.size() > 1){
        long long left = pq.top();
        pq.pop();
        long long right = pq.top();

        pq.push(left + right);
        pq.pop();

        res += left + right;
    }

    cout << res;

    return 0;
}