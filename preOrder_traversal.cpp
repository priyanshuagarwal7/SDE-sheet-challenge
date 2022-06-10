#include<bits/stdc++.h>
/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
vector<int> v;
void preOrder(TreeNode *ptr){
    if(ptr==NULL){
        return ;
    }
    v.push_back(ptr->data);
    preOrder(ptr->left);
    preOrder(ptr->right);
    return ;
}
vector<int> getPreOrderTraversal(TreeNode *root)
{
    // Write your code here.
    preOrder(root);
    vector<int> x = v;
    v.clear();
    return x;
}
