#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    stack<int> que;

    while(n--){
        int k;
        cin >> k;
        
        if(que.empty()){
            cout << -1 << " ";
        }
        else{
            bool b = true;
            while(!que.empty()){
                if(que.top() <= k){
                    b = false;
                    cout << que.top() << " ";
                    break;
                }
                que.pop();
            }
            if(b)cout << -1 << " ";
        }
        que.push(k);
    }
    

    


    return 0;
}