#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;

    stack<char> word;

    for(char i : s){
        if(!word.empty() && i == word.top()){
            word.pop();
        }
        else word.push(i);
    }

    cout << (word.empty() ? "Yes" : "No");
    

    return 0;
}