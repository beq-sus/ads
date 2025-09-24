#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
	int data;
	int mult;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int data) {
		this->data = data;
		mult = 1;
		left = NULL;
		right = NULL;
	} 
};

TreeNode* getMin(TreeNode* root) {
	while (root->left != NULL) {
		root = root->left;
	}
	return root;
}

TreeNode* insert(TreeNode* root, int x){
    if(!root){
        return new TreeNode(x);
    }
	if(root->data == x){
		root->mult++;
	}
    else if(root->data > x){
        root->left = insert(root->left , x);
    } else {
        root->right = insert(root->right, x);
    }
    return root;
}

TreeNode* deleteNode(TreeNode* root, int data) {
	if (root == NULL) {
		return NULL;
	} else if (root->data > data) {
		root->left = deleteNode(root->left, data);
	} else if (root->data < data) {
		root->right = deleteNode(root->right, data);
	} else {
		if(root->mult > 1){
			root->mult--;
		} else {
			if (root->left == NULL && root->right == NULL) {
				delete root;
				return NULL;
			} else if (root->right == NULL) {
				TreeNode* temp = root->left;
				delete root;
				return temp;
			} else if (root->left == NULL) {
				TreeNode* temp = root->right;
				delete root;
				return temp;
			}
			TreeNode* temp = getMin(root->right);
			root->data = temp->data;
			root->mult = temp->mult;
			root->right = deleteNode(root->right, temp->data);
			return root;
		}
	}
	return root;
}

int count(TreeNode* root, int x){
	if(!root)return 0;
	if(root->data == x)return root->mult;
	else if(root->data < x) return count(root->right, x);
	else return count(root->left, x);
}



int main(){
	int n; 
	cin >> n;
	TreeNode* root = nullptr;
	for(int i = 0; i < n; i++){
		int k;
		string s;
		cin >> s >> k;
		if(s == "insert"){
			root = insert(root, k);
		} else if (s == "delete"){
			root = deleteNode(root, k);
		} else if (s == "cnt"){
			cout << count(root, k) << endl;
		}
	}

	return 0;
}