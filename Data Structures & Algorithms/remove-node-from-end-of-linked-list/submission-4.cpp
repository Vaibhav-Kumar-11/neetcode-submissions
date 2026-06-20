class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0, head);
        ListNode* slow = &dummy;
        ListNode* fast = &dummy;

        for(int i=0; i<n; i++){
            fast = fast->next;
        }

        while(fast->next!=NULL){
            slow = slow->next;
            fast = fast->next;
        }

        ListNode* toDelete = slow->next;
        slow->next = slow->next->next;
        toDelete->next = NULL;
        delete(toDelete);
        return dummy.next;
    }
};