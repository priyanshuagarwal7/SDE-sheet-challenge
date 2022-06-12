/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
int t = 1;
int x = 0;
void inOrder(TreeNode<int> *ptr , int k){
    if(t > k){
        return ;
    }
    else{
        if(ptr==NULL){
            return ;
        }
        inOrder(ptr->left , k);
        if(t==k){
            x = ptr->data;
            t++;
            return ;
        }
        else{
            t++;
        }
        inOrder(ptr->right , k);
    }
    return ;
}
int kthSmallest(TreeNode<int> *root, int k)
{
    inOrder(root , k);
    int p = x;
    x = 0 , t = 1;
    return p;
}
