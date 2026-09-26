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
    ListNode* getMid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* merge(ListNode* first, ListNode* second){
        ListNode* temp = new ListNode(0);
        ListNode* curr  = temp;
        while(first != NULL && second != NULL){
            if(first->val <= second->val){
                curr->next = first;
                first = first->next;
            }
            else{
                curr->next = second;
                second = second->next;
            }
            curr = curr->next;
        }
        if (first != NULL) {
            curr->next = first;
        }

        if (second != NULL) {
            curr->next = second;
        }

        return temp->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* mid = getMid(head);
        ListNode* second = mid->next;
        mid->next = NULL;
        ListNode* first = sortList(head);
        second = sortList(second);

        return merge(first, second);
    }
};