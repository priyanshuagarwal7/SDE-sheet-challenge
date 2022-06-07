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

bool detectCycle(Node *head)
{
    map<Node * , int> mp;
    Node *t = head;
    bool ans = false;
    while(t!=NULL){
        if(mp[t]==0){
            mp[t]++;
        }
        else{
            ans = true;
            break;
        }
        t = t->next;
    }
    return ans;
}
