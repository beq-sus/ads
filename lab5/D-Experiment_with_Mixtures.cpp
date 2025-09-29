#include <bits/stdc++.h>
using namespace std;

int main(){
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    
    int n, m;
    cin >> n >> m;

    while(n--){
        long long num;
        cin >> num;
        pq.push(num);
    }
    if(pq.top() > m){
        cout << 0;
        return 0;
    }

    int cnt = 0;

    while(pq.size() > 1){
        long long d1 = pq.top();
        pq.pop();
        long long d2 = pq.top();
        pq.pop();
        
        pq.push(d1 + d2 * 2);
        cnt++;
        if(pq.top() > m)break;
    }
    cout << (pq.top() > m ? cnt : -1);

    return 0;
}