#include <bits/stdc++.h>
using namespace std;

int part(vector<long long>& arr, int low, int high){
    long long pivot = arr[high];
    int i = low - 1;

    for(int j = low; j < high; j++){
        if(arr[j] < pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i+1], arr[high]);
    return i + 1;
}

void quickSort(vector<long long>& arr, int low, int high){
    if(low < high){
        int pi = part(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main(){
    int n;
    cin >> n;
    vector<long long> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    quickSort(v, 0, n-1);

    long long min_diff = abs(v[1] - v[0]);
    for(int i = 1; i < n; i++){
        min_diff = min(min_diff, abs(v[i] - v[i-1]));
    }
    for(int i = 1; i < n; i++){
        if(abs(v[i] - v[i-1]) == min_diff)cout << v[i-1] << " " << v[i] << " ";
    }
    
    

    return 0;
}