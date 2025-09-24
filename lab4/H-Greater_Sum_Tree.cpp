#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x){
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

TreeNode* insert(TreeNode* root, int x){
    if(!root){
        return new TreeNode(x);
    }
    if(root->val > x){
        root->left = insert(root->left , x);
    } else {
        root->right = insert(root->right, x);
    }
    return root;
}

void sum(TreeNode* root, int& cnt){
    if(!root)return;
    if(root->right) sum(root->right, cnt);
    cnt += root->val;
    cout << cnt << " ";
    if(root->left) sum(root->left, cnt);
}



int main(){
    int n;
    cin >> n;
    TreeNode* root = nullptr;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        root = insert(root, num);
    }

    int cnt = 0;
    
    sum(root, cnt);

    
    return 0;
}