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
    ListNode* reverseLL(ListNode* head) {
        ListNode* curr = head;
        ListNode* front = NULL;
        ListNode* prev = NULL;
        while (curr != NULL) {
            front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }
        return prev;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == NULL || left == right) {
            return head;
        }
        ListNode* temp = head;
        ListNode* leftp = NULL;
        ListNode* rightp = NULL;
        ListNode* prevleft = NULL;

        int cnt = 1;

        while (temp != NULL) {
            if (cnt == left - 1) {
                prevleft = temp;
            }
            if (cnt == left) {
                leftp = temp;
            }

            if (cnt == right) {
                rightp = temp;
            }
            temp = temp->next;
            cnt++;
        }
        ListNode* rightNext = rightp->next;
        rightp->next = NULL;
        ListNode* newHead = reverseLL(leftp);

        if (prevleft != NULL)
            prevleft->next = newHead;
        else
            head = newHead;

        leftp->next = rightNext;

        return head;
    }
};