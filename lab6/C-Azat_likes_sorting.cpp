#include <bits/stdc++.h>
using namespace std;

int part(string& s, int low, int high){
    int pivot = s[high];
    int i = low - 1;

    for(int j = low; j < high; j++){
        if(pivot > s[j]){
            i++;
            swap(s[i], s[j]);
        }
    }
    swap(s[i+1], s[high]);
    return i + 1;
}

void qSort(string& s, int low, int high){
    if(low < high){
        int pi = part(s, low, high);

        qSort(s, low, pi-1);
        qSort(s, pi+1, high);
    }
}

int main(){
    string s;
    cin >> s;
    qSort(s, 0, s.size()-1);
    cout << s;
    

    return 0;
}