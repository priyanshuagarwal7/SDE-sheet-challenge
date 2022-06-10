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
void Inorder(TreeNode *ptr){
    if(ptr==NULL){
        return ;
    }
    Inorder(ptr->left);
    v.push_back(ptr->data);
    Inorder(ptr->right);
    return ;
}
vector<int> getInOrderTraversal(TreeNode *root)
{
     Inorder(root);
    vector<int> x = v;
    v.clear();
    return x;
}
