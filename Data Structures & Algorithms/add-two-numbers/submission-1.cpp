class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* newHead = new ListNode(-1);
        ListNode* temp = newHead;
        int carry = 0;

        while (l1 != NULL && l2 != NULL) {
            int num = l1->val + l2->val + carry;
            temp->next = new ListNode(num % 10);
            carry = num / 10;
            l1 = l1->next;
            l2 = l2->next;
            temp = temp->next;
        }

        // ye acha step seekha as of how can you merge both
        // wrna jo mne likha tha wo same tha pr do block of code me tha 
        
        ListNode* remaining = (l1 != NULL) ? l1 : l2;
        while (remaining != NULL) {
            int num = remaining->val + carry;
            temp->next = new ListNode(num % 10);
            carry = num / 10;
            remaining = remaining->next;
            temp = temp->next;
        }

        // Ab apan handle krskte hai any leftover carry agr carry 0 hai to wo push nhi krna
        if (carry != 0) {
            temp->next = new ListNode(carry);
        }

        return newHead->next;
    }
};