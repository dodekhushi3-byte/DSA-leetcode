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
    ListNode* mergeLL(ListNode* l1, ListNode* l2) {

    ListNode dummy(0);
    ListNode* temp = &dummy;

    while (l1 != NULL && l2 != NULL) {
        if (l1->val <= l2->val) {
            temp->next = l1;
            l1 = l1->next;
        }else {
            temp->next = l2;
            l2 = l2->next;
        }
        temp = temp->next;
    }
    if (l1 != NULL)
        temp->next = l1;

    if (l2 != NULL)
        temp->next = l2;

    return dummy.next;
}

    ListNode* partition(int st, int end, vector<ListNode*>& lists){
        if(st > end){ 
            return NULL;
            }
        if(st == end) {
            return lists[st];
        }

        int mid = st + (end - st) / 2;
        ListNode* l1 = partition(st,mid,lists);
        ListNode* l2 = partition(mid+1,end,lists);

        return mergeLL(l1,l2);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if(k ==0) return NULL;
        return partition(0, k-1,lists);
    }
};