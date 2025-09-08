#include <bits/stdc++.h>
  
using namespace std;

struct ListNode{
	ListNode * prev;
	ListNode * next;
	string val;
	ListNode(string _val){
		prev = NULL;
		next = NULL;
		val = _val;
	}	
};

ListNode * head = nullptr;
ListNode * tail = nullptr;
int cnt;
void add_back(string s){
    if(!head){
        head = new ListNode(s);
        return;
    }

    ListNode* node = new ListNode(s);
    ListNode* dum = head;
    while(dum->next)
        dum = dum->next;
    
    dum->next = node;
    dum->next->prev = dum; 
}
void add_front(string s){
    if(!head){
        head = new ListNode(s);
        return;
    }

    ListNode* node = new ListNode(s);

    head->prev = node;
    head->prev->next = head;
    head = head->prev;
}
bool empty(){
    return !head;
}
void erase_front(){
    if(!head->next){
        head = nullptr;
        return;
    }
    head = head->next;
    head->prev = nullptr;
}
void erase_back(){
    ListNode* dum = head;
    if(!dum->next){
        head = nullptr;
        return;
    }
    while(dum->next->next)
        dum = dum->next;
    ListNode* temp = dum->next;
    dum->next = nullptr;
    temp->next = nullptr;
}
string front(){
    return head->val;
}
string back(){
    ListNode* dum = head;
    while(dum->next){
        dum = dum->next;
    }
    return dum->val;
}
void clear(){
    head = nullptr;
}
  
int main()
{
	string s;
   	while(cin >> s){
   		if(s == "add_front"){
   			string t;
   			cin >> t;
   			add_front(t);
   			cout << "ok" << endl;
   		}
   		if(s == "add_back"){
   			string t;
   			cin >> t;
   			add_back(t);
   			cout << "ok" << endl;
   		}
   		if(s == "erase_front"){
   			if(empty()){
   				cout << "error" << endl;
   			}
   			else
   			{
   				cout << front() << endl;
   				erase_front();
   			}
   		}
   		if(s == "erase_back"){
   			if(empty()){
   				cout << "error" << endl;
   			}
   			else{
   				cout << back() << endl;
   				erase_back();
   			}
   		}
   		if(s == "front"){
   			if(empty()){
   				cout << "error" << endl;
   			}
   			else{
   				cout << front() << endl;
   			}
   		}
   		if(s == "back"){
   			if(empty()){
   				cout << "error" << endl;
   			}
   			else{
   				cout << back() << endl;
   			}
   		}
   		if(s == "clear"){
   			clear();
   			cout << "ok" << endl;
   		}
   		if(s == "exit"){
   			cout << "goodbye" << endl;
   			break;
   		}
   	}
    return 0;
}