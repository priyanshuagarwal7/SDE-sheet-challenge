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
void postOrder(TreeNode *ptr){
    if(ptr==NULL){
        return ;
    }
    postOrder(ptr->left);
    postOrder(ptr->right);
    v.push_back(ptr->data);
    return ;
}
vector<int> getPostOrderTraversal(TreeNode *root)
{
    // Write your code here.
    postOrder(root);
    vector<int> x = v;
    v.clear();
    return x;
}
