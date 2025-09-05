#include <bits/stdc++.h>
using namespace std;

void res(int n){
    deque<int> dq;
    int c = 1;

    while(n){
        int m = n % c;
        dq.push_front(n--);

        for(int i = 0; i < m; i++){
            dq.push_front(dq.back());
            dq.pop_back();
        }
        c++;
    }
    
    for(int i : dq){
        cout << i << " ";
    }
}

int main(){
    int n;
    cin >> n;

    while(n--){
        int m;
        cin >> m;
        res(m);

        cout << endl;
    }


    return 0;
}