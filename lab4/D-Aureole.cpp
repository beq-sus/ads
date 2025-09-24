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


int nodesize(TreeNode* root){
    if(!root)return 0;
    return 1 + max(nodesize(root->left), nodesize(root->right));
}

void sums(TreeNode* root, vector<int>& v, int i){
    if(!root)return;
    v[i] += root->val;
    sums(root->left, v, i + 1);
    sums(root->right, v, i + 1);
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
    int k = nodesize(root);
    vector<int> v(k, 0);

    sums(root, v, 0);

    cout << k << endl;
    for(int i : v)cout << i << " ";
    




    return 0;
}