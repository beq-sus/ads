#include <bits/stdc++.h>
using namespace std;

int main(){
    priority_queue<long long, vector<long long>, greater<long long>> pq, temp;
    
    int n, m;
    cin >> n >> m;
    long long sum = 0;

    while(n--){
        string s;
        long long k;
        cin >> s;
        
        if(s == "insert"){
            cin >> k;

            if(pq.size() < m){
                pq.push(k);
                sum += k;
            } else {
                if(k > pq.top()){
                    sum -= pq.top();
                    pq.pop();
                    pq.push(k);
                    sum += k;
                }
            }
        } else if(s == "print") {
            cout << sum << endl;
        }
    }

    return 0;
}