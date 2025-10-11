#include <bits/stdc++.h>
using namespace std;


void heapify(string& v, int n, int i){
    int largest = i;
    int l = i * 2 + 1;
    int r = i * 2 + 2;
    if(l < n && v[l] > v[largest])
        largest = l;
    
    if(r < n && v[r] > v[largest])
        largest = r;
    
    if(i != largest){
        swap(v[i], v[largest]);

        heapify(v, n, largest);
    }
}

void heapsort(string& v){
    int n = v.size();

    for(int i = n / 2 - 1; i >= 0; i--){
        heapify(v, n, i);
    }

    for(int i = n - 1; i > 0; i--){
        swap(v[0], v[i]);

        heapify(v, i, 0);
    }
}
bool isvowel(char ch){
    return ch == 'a' || ch == 'e' || ch == 'u' || ch == 'i' || ch == 'o';
}

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;

    string vowel, consonant;
    for(char i : s){
        if(isvowel(i))vowel += i;
        else consonant += i;
    }
    heapsort(vowel);
    heapsort(consonant);
    cout << vowel + consonant;
    

    return 0;
}