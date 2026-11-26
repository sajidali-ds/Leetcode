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
    ListNode* partition(ListNode* head, int x) {
        ListNode* small=new ListNode(0);
        ListNode* large=new ListNode(0);

        ListNode* smallpointer=small;
        ListNode* largepointer=large;

        while(head != NULL){
            
            if(head->val < x){
                smallpointer->next=head;
                smallpointer=smallpointer->next;
            }
            else{
                largepointer->next=head;
                largepointer=largepointer->next;
            }
            head=head->next;
        }
        smallpointer->next=large->next;
        largepointer->next=NULL;
        return small->next;
    }
};