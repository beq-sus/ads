#include <bits/stdc++.h>
using namespace std;

int main(){
    priority_queue<long long> pq;
    
    int n, x;
    cin >> n >> x;
    while(n--){
        long long num;
        cin >> num;
        pq.push(num);
    }

    long long res = 0;

    while(x--){
        long long a = pq.top();
        pq.pop();
        res += a;
        if(a > 0)pq.push(a-1);
    }
    
    cout << res;

    return 0;
}