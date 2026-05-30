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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL || head->next==NULL) return NULL;
        ListNode* temp = head;
        int size = 0;
        while(temp!=NULL){
            size++;
            temp = temp->next;
        }

        int rem = size-n;
        if(rem==0){
            return head->next;
        }
        int cnt = 0;
        ListNode* newTemp = head;
        while(cnt<rem-1){
            cnt++;
            newTemp = newTemp->next;
        }
        ListNode* toDelete = newTemp->next;
        newTemp->next = toDelete->next;
        toDelete->next = nullptr;
        delete toDelete;
        return head;
    }
};
