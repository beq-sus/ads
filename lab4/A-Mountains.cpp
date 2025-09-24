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

bool path(TreeNode* root, string s){
    if(!root)return false;
    for(char i : s){
        if(i == 'L'){
            if(root->left)root = root->left;
            else return false;
        }
        else {
            if(root->right)root = root->right;
            else return false;
        }
    }
    return root;
}



int main(){
    int n, k;
    cin >> n >> k;
    TreeNode* root = nullptr;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        root = insert(root, num);
    }
    
    while(k--){
        string s;
        cin >> s;
        cout << ( path(root, s) ? "YES" : "NO") << endl;
        
    }

    return 0;
}