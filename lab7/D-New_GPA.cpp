#include <bits/stdc++.h>
using namespace std;

bool comp(pair<pair<string, string>, double> a, pair<pair<string, string>, double> b){
    if(a.second != b.second)return a.second < b.second;
    if(a.first.first != b.first.first)return a.first.first < b.first.first;
    return a.first.second < b.first.second;
}


void merge(vector<pair<pair<string, string>, double>>& v, int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<pair<pair<string, string>, double>> l(n1), r(n2);
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

void merge_sort(vector<pair<pair<string, string>, double>>& v, int left, int right){
    if(left >= right)return;

    int mid = (left + right) / 2;
    merge_sort(v, left, mid);
    merge_sort(v, mid+1, right);
    merge(v, left, mid, right);
}

int main(){
    int n;
    cin >> n;
    map<string, double> grades{
        {"A+", 4.0},
        {"A", 3.75},
        {"B+", 3.50},
        {"B", 3.0},
        {"C+", 2.50},
        {"C", 2.0},
        {"D+", 1.50},
        {"D", 1.0},
        {"F", 0.0}
    };

    vector<pair<pair<string, string>, double>> v;
    for(int i = 0; i < n; i++){
        string first_name, second_name;
        int m;
        cin >> first_name >> second_name >> m;
        double  g = 0.0, c = 0.0;  
        for(int j = 0; j < m; j++){
            string s;
            int k;
            cin >> s >> k;
            g += k * grades[s];
            c += k;
        }
        v.push_back({{first_name, second_name}, g / c});
    }

    merge_sort(v, 0, n-1);

    for(pair<pair<string, string>, double> i : v){
        cout << i.first.first + " " + i.first.second + " " << fixed << setprecision(3) << i.second * 1.0 << endl; 
    }
    return 0;
}