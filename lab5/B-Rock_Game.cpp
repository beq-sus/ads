#include <bits/stdc++.h>
using namespace std;

int main(){
    priority_queue<long long> pq;
    
    int n;
    cin >> n;
    while(n--){
        long long num;
        cin >> num;
        pq.push(num);
    }

    while(pq.size() > 1){
        long long y = pq.top();
        pq.pop();
        long long x = pq.top();
        pq.pop();
        if(y - x > 0)pq.push(y - x);
    }
    
    cout << (pq.size() > 0 ? pq.top() : 0);

    return 0;
}