#include<bits/stdc++.h>
/*
    ----------------- Binary Tree node class for reference -----------------

    template <typename T>
    class BinaryTreeNode {
        public : 
            T data;
            BinaryTreeNode<T> *left;
            BinaryTreeNode<T> *right;
            BinaryTreeNode<T> *next;

            BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
                next = NULL;
            }
    };
*/

void connectNodes(BinaryTreeNode< int > *root) {
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while(q.size() > 0){
        int size = q.size();
        for(int index = 0 ; index < size ; index++){
            BinaryTreeNode<int> *ptr = q.front();
            q.pop();
            if(index==size-1){
                ptr->next = NULL;
            }
            else{
                ptr->next = q.front();
            }
            if(ptr->left!=NULL){
                q.push(ptr->left);
            }
            if(ptr->right!=NULL){
                q.push(ptr->right);
            }
        }
    }
}
