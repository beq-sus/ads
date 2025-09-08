#include <bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;

    ListNode(int x){
        val = x;
        next = nullptr;
    }
};

int main(){
    int n;
    cin >> n;

    ListNode* arr = new ListNode(0);
    ListNode* dum = arr;

    for(int i = 0; i < n; i++){
        int k;
        cin >> k;
        dum->next = new ListNode(k);
        dum = dum->next;
    }

    int k, idx;
    cin >> k >> idx;

    dum = arr;
    
    for(int i = 0; i < idx; i++){
        dum = dum->next;
    }

    ListNode* temp = dum->next;
    dum->next = new ListNode(k);
    dum = dum->next;
    dum->next = temp;

    ListNode* curr = arr->next;
    while(curr){
        cout << curr->val << " ";
        curr = curr->next;
    }

    

    return 0;
}