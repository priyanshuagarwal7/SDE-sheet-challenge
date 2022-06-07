/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode *createNode(int x){
        ListNode *ptr = NULL;
        ptr = new ListNode(x);
        return ptr;
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *head = NULL , *ptr = NULL;
        while(list1!=NULL && list2!=NULL){
            int f = list1->val , s = list2->val;
            if(f > s){
                if(head==NULL){
                    ptr = createNode(s);
                    head = ptr;
                }
                else{
                    ptr->next = createNode(s);
                    ptr = ptr->next;
                }
                list2 = list2->next;
            }
            else if(s > f){
                if(head==NULL){
                    ptr = createNode(f);
                    head = ptr;
                }
                else{
                    ptr->next = createNode(f);
                    ptr = ptr->next;
                }
                list1 = list1->next;
            }
            else if(s==f){
                if(head==NULL){
                    ptr = createNode(s);
                    head = ptr;
                    ptr->next = createNode(s);
                    ptr = ptr->next;
                }
                else{
                    ptr->next = createNode(s);
                    ptr = ptr->next;
                    ptr->next = createNode(s);
                    ptr = ptr->next;
                }
                list1 = list1->next;
                list2 = list2->next;
            }
        }
        if(list1!=NULL){
            if(ptr==NULL){
                ptr = list1;
                head = ptr;
            }
            else{
                ptr->next = list1;
            }
        }
        else if(list2!=NULL){
            if(ptr==NULL){
                ptr = list2;
                head = ptr;
            }
            else{
                ptr->next = list2;
            }
        }
        return head;
    }
};
