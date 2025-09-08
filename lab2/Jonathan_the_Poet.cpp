#include <bits/stdc++.h>
using namespace std;

struct ListNode{
    string val;
    ListNode* 7;

    ListNode(string x){
        val = x;
        next = nullptr;
    }
};

int main(){

    int n, k;
    cin >> n >> k;

    ListNode* poem = new ListNode("a");
    ListNode* dum = poem;

    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        dum->next = new ListNode(s);
        dum = dum->next;
    }

    ListNode* prev = poem;

    while(k--){
        prev = prev->next;
    }
    ListNode* half = prev->next;
    prev->next = nullptr;
    dum->next = poem->next;
    poem->next = half;

    ListNode* temp = poem->next;
    while(temp){
        cout << temp->val << " ";
        temp = temp->next;
    }


    

    return 0;
}