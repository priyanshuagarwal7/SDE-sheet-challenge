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

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    LinkedListNode<int> * ptr = head , *temp = head;
    if(ptr==NULL){
        
    }
    else if(ptr->next!=NULL){
        LinkedListNode<int> * var = head->next;
        ptr->next = NULL , temp = var , var = var->next , temp->next = ptr , ptr = temp;
        while(var!=NULL){
            temp = var , var = var->next , temp->next = ptr , ptr = temp;
        }
    }
    return ptr;
}
