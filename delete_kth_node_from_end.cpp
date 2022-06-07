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

LinkedListNode<int>* removeKthNode(LinkedListNode<int> *head, int K)
{
    LinkedListNode<int> *ptr = head;
    int count = 0;
    while(ptr!=NULL){
        count++;
        ptr = ptr->next;
    }
    if(K>0){
        int t = count-K+1;
        LinkedListNode<int> *var = head , *temp = head;
        int total = 1;
        if(t==1){
            head = head->next;
        }
        else{
            while(total!=t){
                if(total==1){
                    temp = temp->next;
                }
                else{
                    var = var->next , temp = temp->next;
                }
                total++;
            }
            if(temp!=NULL){
                var->next = temp->next;
            }
        }
    }
    
    return head;
}
