#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    long long val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(long long x){
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

TreeNode* insert(TreeNode* root, long long x){
    if(!root){
        return new TreeNode(x);
    }

    if(root->val > x){
        root->left = insert(root->left , x);
    } else if(root->val < x){
        root->right = insert(root->right, x);
    }

    return root;
}

long dfs(TreeNode* root, long& cnt){
    if(!root)return 0;

    long left = dfs(root->left, cnt);
    long right = dfs(root->right, cnt);
    cnt = max(cnt, left + right + 1); 
    
    return 1 + max(left, right);
}

int main(){
    long n;
    cin >> n;
    TreeNode* root = nullptr;

    for(int i = 0; i < n; i++){
        long long num;
        cin >> num;
        root = insert(root, num);
    }
    

    long res = 0;
    dfs(root, res);
    
    cout << res;
    return 0;
}