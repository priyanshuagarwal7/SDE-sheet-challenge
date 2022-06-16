#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/
Node *reverse(Node *start){
    Node *ptr = start , *var = start->next , *temp = start->next;
    ptr->next = NULL;
    while(var!=NULL){
        var = var->next , temp->next = ptr , ptr = temp , temp = var;
    }
    return ptr;
}
Node *getListAfterReverseOperation(Node *head, int n, int b[]){
    Node *itr = head;
    int count = 0 , sum = 0;
    while(itr!=NULL){
        itr = itr->next , count++;
    }
    int index = 0;
    for(int i = 0 ; i<n ; i++){
        sum+=b[i];
        if(sum >= count){
            index = i;
            break;
        }
    }
    if(index==0){
        index = n-1;
    }
    Node *ptr = head , *h = head , *t = head , *ans = head , *y = NULL;
    for(int i = 0 ; i<=index ; i++){
        int x = b[i];
        Node *start = t;
        if(x==0){
            continue;
        }
        if(start==NULL){
            break;
        }
        if(i==0){
            while(x>1 && ptr!=NULL){
                if(x!=b[i]){
                    h = h->next;
                }
                ptr = ptr->next;
                x--;
            }
            Node *rev_start = NULL;
            if(ptr==NULL){
                rev_start = reverse(start);
                t = NULL;
            }
            else{
                t = ptr->next;
                ptr->next = NULL;
                rev_start = reverse(start);
            }
            ans = rev_start;
            y = ans;
            while(y->next!=NULL){
                y = y->next;
            }
            y->next = t;
        }
        else{
            y->next = NULL;
            while(x>1 && ptr!=NULL){
                if(x!=b[i]){
                    h = h->next;
                }
                ptr = ptr->next;
                x--;
            }
            Node *rev_start = NULL;
            if(ptr==NULL){
                rev_start = reverse(start);
                t = NULL;
            }
            else{
                t = ptr->next;
                ptr->next = NULL;
                rev_start = reverse(start);
            }
            Node *u = rev_start;
            while(u->next!=NULL){
                u = u->next;
            }
            y->next = rev_start;
            y = u;
            y->next = t;
        }
        ptr = t;
        h = ptr;
    }
    return ans;
}
