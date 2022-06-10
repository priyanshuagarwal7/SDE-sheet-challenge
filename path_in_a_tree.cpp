#include<bits/stdc++.h>
/*   
    template <typename T = int>
	class TreeNode
	{
		public:
		T data;
		TreeNode<T> *left;
		TreeNode<T> *right;

		TreeNode(T data)
		{
			this->data = data;
			left = NULL;
			right = NULL;
		}

		~TreeNode()
		{
			if (left != NULL)
			{
		  		delete left;
			}
			if (right != NULL)
			{
			 	delete right;
			}
		}
	};
*/

vector<int> v;
bool func(TreeNode<int> *ptr , int target){
    if(ptr==NULL){
        return false;
    }
    if(ptr->data==target){
        v.push_back(ptr->data);
        return true;
    }
    bool k = func(ptr->left , target);
    if(k==true){
        v.push_back(ptr->data);
    }
    else{
        k = func(ptr->right , target);
        if(k==true){
            v.push_back(ptr->data);
        }
    }
    return k;
}
vector<int> pathInATree(TreeNode<int> *root, int x)
{
    // Write your code here.
    bool alpha = func(root , x);
    if(alpha==true){
//         v.push_back(root->data);
    }
    vector<int> p = v;
    reverse(p.begin() , p.end());
    v.clear();
    return p;
}
