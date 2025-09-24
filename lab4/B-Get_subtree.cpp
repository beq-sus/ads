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

int nodesize(TreeNode* root, int k){
    if(!root)return 0;
    if(root->val == k)return 0;
    return 1 + nodesize(root->left, k) + nodesize(root->right, k);
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

    int k;
    cin >> k;
    cout << n - nodesize(root, k);
    


    return 0;
}