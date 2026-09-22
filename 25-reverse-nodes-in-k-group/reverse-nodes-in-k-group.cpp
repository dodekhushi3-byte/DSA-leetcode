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
        ListNode* prev = NULL;
        while (curr != NULL) {
            ListNode* front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }
        return prev;
    }

    ListNode* getKthnode(ListNode* head, int k) {
        ListNode* temp = head;
        k -= 1;
        while (temp != NULL && k > 0) {
            k--;
            temp = temp->next;
        }
        return temp;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prev = NULL;
        while (temp != NULL) {
            ListNode* kthnode = getKthnode(temp, k);
            if (kthnode == NULL) {
                if (prev) {
                    prev->next = temp;
                }
                break;
            }
            ListNode* newhead = kthnode->next;
            kthnode->next = NULL;
            reverseLL(temp);
            if(temp == head){
                head = kthnode;
            }else{
                prev->next = kthnode;
            }
            prev = temp;
            temp = newhead;

        }
        return head;
    }
};