
class Solution {
public:
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;

        while(head){
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }

        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=NULL &&fast->next->next !=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* newHead=reverse(slow->next);
        ListNode* first=head;
        ListNode* second=newHead;
        while(second!=NULL){
            if(first->val != second->val){
               reverse(newHead);
               return false;
            }
            first=first->next;
            second=second->next;


        }
        reverse(newHead);
        return true;
    }
};