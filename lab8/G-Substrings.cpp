#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    int q;
    
    cin >> s;
    cin >> q;
    
    while (q--) {
        int l, r;
        cin >> l >> r;
        
        string pattern = s.substr(l - 1, r - l + 1);
        
        int count = 0;
        size_t pos = 0;
        
        while ((pos = s.find(pattern, pos)) != string::npos) {
            count++;
            pos++;
        }
        
        cout << count << endl;
    }
    
    return 0;
}