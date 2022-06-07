#include <bits/stdc++.h> 
/********************************

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

********************************/


Node *rotate(Node *head, int k) {
    Node *ptr = head;
    int count = 0;
    while(ptr!=NULL){
        count++;
        ptr = ptr->next;
    }
    if(k > count){
        k = k%count;
    }
    int t = count-k;
    if(t!=0 && t!=count && t>0){
        Node *var = head;
        int x = 1;
        while(x!=t){
            var = var->next;
            x++;
        }
        Node *temp = var->next;
        var->next = NULL;
        Node *v = temp;
        while(v->next!=NULL){
            v = v->next;
        }
        v->next = head;
        head = temp;
    }
    return head;
}
