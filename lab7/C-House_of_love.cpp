#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& v, int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> l(n1), r(n2);
    for(int i = 0; i < n1; i++)l[i] = v[left + i];
    for(int i = 0; i < n2; i++)r[i] = v[mid + 1 + i];

    int i = 0, j = 0, k = left;
    
    while(i < n1 && j < n2){
        if(l[i] <= r[j]){
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

void merge_sort(vector<int>& v, int left, int right){
    if(left >= right)return;

    int mid = (left + right) / 2;
    merge_sort(v, left, mid);
    merge_sort(v, mid+1, right);
    merge(v, left, mid, right);
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> f1(n), f2(m);

    for(int i = 0; i < n; i++){
        cin >> f1[i];
    }
    for(int i = 0; i < m; i++){
        cin >> f2[i];
    }

    merge_sort(f1, 0, n-1);
    merge_sort(f2, 0, m-1);

    int i = 0;
    int j = 0;
    while(i < n && j < m){
        if(f1[i] == f2[j]){
            cout << f1[i] << " ";
            i++;
            j++;
        }else if(f1[i] < f2[j]){
            i++;
        }
        else j++;
    }


    return 0;
}