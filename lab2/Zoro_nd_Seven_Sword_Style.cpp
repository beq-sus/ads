#include <iostream>
 
using namespace std;
 
struct ListNode{
    int val;
    ListNode* next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {}
    ListNode(ListNode* next): val(0), next(next) {}
    ListNode(int x, ListNode* next): val(x), next(next) {}
};
 
ListNode* insert(ListNode* head, ListNode* node, int p){
    /* write your code here */
    if(p == 0){
        node->next = head;
        return node;
    }
    ListNode* dum = head;
    for(int i = 0; i < p-1; i++){
        dum = dum->next;
    }

    ListNode* temp = dum->next;
    dum->next = node;
    dum->next->next = temp;
    return head;
}
 
ListNode* remove(ListNode* head, int p){
    /* write your code here */
    if(p == 0)return head->next;
    
    ListNode* dum = head;
    for(int i = 0; i < p-1; i++){
        dum = dum->next;
    }
    if(dum->next){
        dum->next = dum->next->next;
    }
    else {
        dum->next = nullptr;
    }
    return head;
}

ListNode* replace(ListNode* head, int p1, int p2){
    /* write your code here */
    if(p1 == p2)return head;

    ListNode* left = head;
    ListNode* prevleft = nullptr;
    for(int i = 0; i < max(p1, p2); i++){
        prevleft = left;
        left = left->next;
    }

    ListNode* right = head;
    ListNode* prev = nullptr;
    for(int i = 0; i < min(p1, p2); i++){
        prev = right;
        right = right->next;
    }

    ListNode* dum = right;
    if(p1 < p2){
        dum = right->next;
        right->next = left->next;
        left->next = right;
        if(p1 == 0)return dum;
        prev->next = dum;
    }else{
        prevleft->next = left->next;
        left->next = dum;
        if(p2 == 0)return left;
        prev->next = left;
    }


    
    return head;
}

ListNode* reverse(ListNode* head){
    /* write your code here */
    ListNode* prev = nullptr;
    while(head){
        ListNode* temp = head->next;
        head->next = prev;
        prev = head;
        head = temp;
    }
    return prev;
}
 
void print(ListNode* head){
    /* write your code here */
    while(head){
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

ListNode* cyclic_left(ListNode* head, int x){
    /* write your code here */
    int n = 1;
    ListNode* dum = head;
    while(dum->next){
        dum = dum->next;
        n++;
    }

    int p = x % n;
    if(p == 0)return head;

    ListNode* curr = head;
    for(int i = 0; i < p - 1; i++){
        curr = curr->next;
    }

    ListNode* res = curr->next;
    curr->next = nullptr;
    dum->next = head;

    return res;
}
 
ListNode* cyclic_right(ListNode* head, int x){
    /* write your code here */
    int n = 1;
    ListNode* dum = head;
    while(dum->next){
        dum = dum->next;
        n++;
    }

    int p = x % n;
    if(p == 0)return head;

    ListNode* curr = head;
    for(int i = 0; i <n - p - 1; i++){
        curr = curr->next;
    }

    ListNode* res = curr->next;
    curr->next = nullptr;
    dum->next = head;

    return res;
}
 
int main(){
    ListNode* head = nullptr;
    while (true)
    {
        int command; cin >> command;
        if (command == 0){
            break;
        }else if(command == 1){
            int x, p; cin >> x >> p;
            head = insert(head, new ListNode(x), p);
        }else if (command == 2){
            int p; cin >> p;
            head = remove(head, p);
        }else if (command == 3){
            print(head);
        }else if (command == 4){
            int p1, p2; cin >> p1 >> p2;
            head = replace(head, p1, p2);
        }else if (command == 5){
            head = reverse(head);
        }else if (command == 6){
            int x; cin >> x;
            head = cyclic_left(head, x);
        }else if (command == 7){
            int x; cin >> x;
            head = cyclic_right(head, x);
        }   
    }
    return 0;
}