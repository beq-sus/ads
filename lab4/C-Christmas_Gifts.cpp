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

TreeNode* linebreak(TreeNode* root, int k){
    if(!root)return nullptr;
    if(root->val == k)return root;

    TreeNode* leftnode = linebreak(root->left, k);
    if(leftnode && leftnode->val == k)return leftnode;

    return linebreak(root->right, k);
}

void print_all(TreeNode* root){
    if(!root)return;
    cout << root->val << " ";
    print_all(root->left);
    print_all(root->right);
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

    print_all(linebreak(root, k));


    return 0;
}