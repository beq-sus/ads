#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> nums(n);
    for(int i = 0; i < n; i++)cin >> nums[i];

    int k;
    cin >> k;

    int res = 0;

    for(int i = 1; i < n; i++){
        if(abs(nums[i] - k) < abs(nums[res] - k))res = i;
        // cout << abs(nums[i] - k) << endl;
    }
    cout << res;

    return 0;
}