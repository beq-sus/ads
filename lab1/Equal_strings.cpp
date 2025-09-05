#include <bits/stdc++.h>
using namespace std;

int main(){
    string s1, s2;
    cin >> s1 >> s2;

    stack<char> word1, word2;

    for(char i : s1){
        if(!word1.empty() && i == '#')word1.pop();
        else if(i != '#')word1.push(i);
    }
    for(char i : s2){
        if(!word2.empty() && i == '#')word2.pop();
        else if(i != '#')word2.push(i);
    }

    if(word1 == word2)cout << "Yes";
    else cout << "No";
    

    return 0;
}