#include <bits/stdc++.h>

using namespace std;
/**
 * Definition for a binary tree node.*/
  struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 

struct stack_node{
    TreeNode *node;
    bool left, right;
    
    stack_node(TreeNode* n, bool l, bool r) : node(n), left(l), right(r){}
};

class BSTIterator {
    stack<pair<TreeNode*, pair<bool, bool>>> inorder;
public:
    BSTIterator(TreeNode *root) {
        inorder.push({root, {false, false}});
    }
    
    int next() {
        cout << inorder.size();
        TreeNode* current = inorder.top().first;
        while(current != nullptr and inorder.top().second.first == false){
            inorder.top().second.first = true;
            inorder.push({current, {false, false}});
            current = current->left;
        }
        pair<TreeNode*, pair<bool, bool>> cur_node = {inorder.top().first, inorder.top().second};
        inorder.pop();
        if(cur_node.first-> right != nullptr) inorder.push({cur_node.first->right, {false, false}});
        return cur_node.first -> val;
    }
    
    int hasNext() {
        return inorder.size();
    }
};

int main(){
    TreeNode* root(7);
    root -> val = 7;
    cout << root -> val << "\n";
    // TreeNode* a;
    // root -> val = 3;
    // root -> left = a;
    // TreeNode* b;
    // b -> val = 15;
    // root -> right = b;
    
    // TreeNode* c;
    // c -> val = 9;
    // b -> right = c;
    
    // TreeNode* d;
    // d -> val = 20;
    // b -> right = d;
    // BSTIterator bst(root);
    // cout << bst.next() << "";
}

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */