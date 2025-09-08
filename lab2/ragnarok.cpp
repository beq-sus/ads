# include <iostream>
# include <algorithm>
# include <cassert>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;

  ListNode() {
    val = 0;
    next = NULL;
  }

};



int findMaxSum(int n, ListNode *head) {
	// Implement this function
	ListNode* right = head;
	ListNode* left = head;
    int sum = 0;
    int maxsum = 0;
    while(right->next)
        right = right->next;
        sum += right->val;
    
    maxsum = sum;
    while(left){
      ListNode* temp = left;
      sum = 0;
      while(temp){
        sum += temp->val;
        maxsum = max(sum, maxsum);
        temp = temp->next;
      }
      left = left->next;
    }
    return maxsum;
}

int main() {
  int n;
  cin >> n;

  ListNode *head, *tail;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    ListNode *cur = new ListNode();
    cur -> val = x;

    if (i == 1) {
      head = tail = cur;
    } else {
      tail -> next = cur;
      tail = cur;
    }
  }

  cout << findMaxSum(n, head) << "\n";
  return 0;
}
