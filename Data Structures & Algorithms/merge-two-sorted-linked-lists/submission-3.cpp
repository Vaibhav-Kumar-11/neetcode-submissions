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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL && list2 == NULL) return list1;
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;

        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        ListNode* dummy = new ListNode(0);
        ListNode* ans = dummy;

        while(temp1!=NULL && temp2!=NULL){
            if(temp1->val <= temp2->val){
                ListNode* newTemp1 = temp1->next;
                dummy->next = temp1;
                dummy = dummy->next;
                temp1 = newTemp1;
            }
            else{
                ListNode* newTemp2 = temp2->next;
                dummy->next = temp2;
                dummy = dummy->next;
                temp2 = newTemp2;
            }
        }

        if(temp1 == NULL){
            dummy->next = temp2;
        }
        if(temp2 == NULL){
            dummy->next = temp1;
        }

        return ans->next;
    }
};
