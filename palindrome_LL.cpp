#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

bool isPalindrome(LinkedListNode<int> *head) {
//     LinkedListNode<int> *reverse;
    bool ans = true;
    LinkedListNode<int> *ptr = head , *temp = head , *itr = ptr;
    if(head!=NULL){
        vector<int> v;
        while(itr!=NULL){
            v.push_back(itr->data);
            itr = itr->next;
        }
        LinkedListNode<int> *var = head->next;
        ptr->next = NULL;
        temp = var;
        while(var!=NULL){
            var = var->next;
            temp->next = ptr , ptr = temp , temp = var;
        }
        int i = 0;
        while(ptr!=NULL){
            if(ptr->data!=v[i]){
                ans = false;
                break;
            }
            ptr = ptr->next ;
            i++;
        }
    }
    return ans;
}
