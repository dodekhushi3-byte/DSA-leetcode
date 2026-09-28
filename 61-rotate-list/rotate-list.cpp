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
    int getlength(ListNode* head){
        ListNode* temp = head;
        int cnt = 1;
        while(temp->next != NULL){
            temp = temp->next;
            cnt++;
        }
        return cnt;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* temp = head;
        int kthnode = getlength(temp);
        k = k % kthnode;
        if(k == 0){
            return head;
        }
        int length = kthnode - k -1;
        for(int i = 1; i<= length; i++){
            temp = temp->next;
        }
        ListNode* newnode = temp->next;
        temp->next = NULL;
        ListNode* temp1 = newnode;
        while(temp1->next != NULL){
            temp1 = temp1->next;
        }
        temp1->next = head;
        return newnode;
    }
};