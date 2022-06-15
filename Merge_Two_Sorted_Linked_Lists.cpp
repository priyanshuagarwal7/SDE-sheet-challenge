#include <bits/stdc++.h> 
/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/
Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    Node<int> *ptr = NULL;
    if(first==NULL && second == NULL){
        ptr = NULL;
    }
    else if(first!=NULL && second == NULL){
        ptr = first;
    }
    else if(first==NULL && second!=NULL){
        ptr = second;
    }
    else{
        Node<int> *temp = first , *var = second , *t = first , *v = second , *pointer = NULL;
        int count = 0;
        while(temp!=NULL && var!=NULL){
            if(temp->data > var->data){
                var = var->next;
                v->next = NULL;
                if(count==0){
                    ptr = v;
                    pointer = v;
                    v = var;
                    count++;
                }
                else{
                    pointer->next = v;
                    pointer = pointer->next;
                    v = var;
                }
            }
            else if(temp->data < var->data){
                temp = temp->next;
                t->next = NULL;
                if(count==0){
                    ptr = t;
                    pointer = t;
                    t = temp;
                    count++;
                }
                else{
                    pointer->next = t;
                    pointer = pointer->next;
                    t = temp;
                }
            }
            else{
                temp = temp->next , var = var->next;
                t->next = NULL , v->next = NULL;
                if(count==0){
                    ptr = t;
                    pointer = t;
                    pointer->next = v;
                    pointer = pointer->next;
                    count++;
                }
                else{
                    pointer->next = t;
                    pointer = pointer->next;
                    pointer->next = v;
                    pointer = pointer->next;
                }
                t = temp , v = var;
            }
        }
        while(temp!=NULL){
            pointer->next = temp;
            temp = temp->next;
            pointer = pointer->next;
        }
        while(var!=NULL){
            pointer->next = var;
            var = var->next;
            pointer = pointer->next;
        }
    }
    return ptr;
}
