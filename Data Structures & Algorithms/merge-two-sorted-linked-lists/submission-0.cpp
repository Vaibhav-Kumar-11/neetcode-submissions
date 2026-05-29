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
        if(list1==NULL && list2==NULL) return list1;
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;

        ListNode* temp_1 = list1;
        ListNode* temp_2 = list2;
        vector<int> ans;

        while(temp_1!=NULL){
            ans.push_back(temp_1->val);
            temp_1 = temp_1->next;
        }
        while(temp_2!=NULL){
            ans.push_back(temp_2->val);
            temp_2 = temp_2->next;
        }
        sort(ans.begin(),ans.end());

        ListNode* temp = new ListNode(ans[0]);
        ListNode* newHead = temp;
        for(int i=1; i<ans.size(); i++){
            ListNode* curr = new ListNode(ans[i]);
            temp->next=curr;
            temp=curr;
        }
        return newHead;
    }
};
