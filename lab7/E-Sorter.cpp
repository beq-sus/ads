#include <bits/stdc++.h>
using namespace std;

bool comp(const pair<vector<int>, int>& a, const pair<vector<int>, int>& b){
    if(a.second != b.second)return a.second > b.second;
    int n = a.first.size();
    for(int i = 0; i < n; i++){
        if(a.first[i] != b.first[i])return a.first[i] < b.first[i];
    }
    return a.first[0] < b.first[0];
}


void merge(vector<pair<vector<int> , int>>& v, int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<pair<vector<int> , int>> l(n1), r(n2);
    for(int i = 0; i < n1; i++)l[i] = v[left + i];
    for(int i = 0; i < n2; i++)r[i] = v[mid + 1 + i];

    int i = 0, j = 0, k = left;
    
    while(i < n1 && j < n2){
        if(comp(l[i], r[j])){
            v[k] = l[i];
            i++;
        } else {
            v[k] = r[j];
            j++;
        }
        k++;
    }

    while(i < n1){
        v[k] = l[i];
        i++;
        k++;
    }

    while(j < n2){
        v[k] = r[j];
        j++;
        k++;
    }
}

void merge_sort(vector<pair<vector<int> , int>>& v, int left, int right){
    if(left >= right)return;

    int mid = (left + right) / 2;
    merge_sort(v, left, mid);
    merge_sort(v, mid+1, right);
    merge(v, left, mid, right);
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<pair<vector<int> , int>> v;
    for(int i = 0; i < n; i++){
        pair<vector<int>, int> row;
        int sum = 0;
        for(int i = 0; i < m; i++){
            int num;
            cin >> num;
            sum += num;
            row.first.push_back(num);
        }
        row.second = sum;
        v.push_back(row);
    }

    merge_sort(v, 0, n-1);

    for(pair<vector<int> , int> i : v){
        for(int j : i.first){
            cout << j << " ";
        }
        cout << endl;
    }


    return 0;
}