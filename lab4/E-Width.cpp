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

TreeNode* insert(TreeNode* root, int x, int y, int z){
    if(!root)return nullptr;
    if(root->val == x){
        if(z){
            root->right = new TreeNode(y);
        } else {
            root->left = new TreeNode(y);
        }
    }
    insert(root->left, x, y, z);
    insert(root->right, x, y, z);        
    return root;
}

int nodesize(TreeNode* root){
    if(!root)return 0;
    return 1 + max(nodesize(root->left), nodesize(root->right));
}

void dfs(TreeNode* root, int i, vector<int>& width){
    if(!root)return;

    width[i]++;

    dfs(root->left, i+1, width);
    dfs(root->right, i+1, width);
}

int main(){
    int n;
    cin >> n;
    TreeNode* root = new TreeNode(1);
    for(int i = 1; i < n; i++){
        int x, y, z;
        cin >> x >> y >> z;
        root = insert(root, x, y, z);
    }

    int k = nodesize(root);

    vector<int> width(k);
    dfs(root, 0, width);

    int res = 0;
    for(int i : width)res = max(res, i);

    cout << res;

    return 0;
}