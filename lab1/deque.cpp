#include <bits/stdc++.h>
using namespace std;

int main(){
    char s;
    cin >> s;
    deque<int> dq;
    
    while(s != '!'){
        if(s == '*'){
            if(dq.empty()){
                cout << "error" << endl;
            }
            else {
                cout << dq.front() + dq.back() << endl;
                dq.pop_front();
                if(!dq.empty())dq.pop_back();
            }
        }
        else {
            int k;
            cin >> k;
            if(s == '+')dq.push_front(k);
            else if(s == '-')dq.push_back(k);
        }
        
        cin >> s;
    }


    return 0;
}