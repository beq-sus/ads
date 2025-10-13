#include <bits/stdc++.h>
using namespace std;

bool comp(string a, string b){
    return a.size() < b.size();
}

void merge(vector<string>& v, int left, int mid, int right){
    int n1 = mid + 1 - left;
    int n2 = right - mid;

    vector<string> L(n1), R(n2);
    for (int i = 0; i < n1; i++)
        L[i] = v[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = v[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while(i < n1 && j < n2){
        if(L[i].size() <= R[j].size()){
            v[k] = L[i];
            i++;
        } else {
            v[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < n1){
        v[k] = L[i];
        i++;
        k++;
    }

    while(j < n2){
        v[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(vector<string>& v, int left, int right){
    
    if(left >= right)return;

    int mid = (right + left) / 2;
    merge_sort(v, left, mid);
    merge_sort(v, mid+1, right);
    merge(v, left, mid, right);
}


int main(){
    int t; 
    cin >> t;
    while(t--){
        vector<string> v;
        string str;
        string s;
        while(cin >> s){
            v.push_back(s);
            if(cin.peek() == '\n')break;
        }
        merge_sort(v, 0, v.size()-1);

        for(string i : v)cout << i << " ";
        cout << endl;
    }
    
    return 0;
}