/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * @param head a ListNode
     * @param val an integer
     * @return a ListNode
     */

    ListNode *removeElements(ListNode *head, int val) {
        // Write your code here
        ListNode *p, *q;
        if (head == NULL) 
            return head;
        while (head->val == val) {
            head = head->next; 
            if (head == NULL) 
                return head;
        }
        p = head;
        if (p != NULL) {
            while (p->next != NULL) {
                if (p->next->val == val) {
                    q = p->next;
                    p->next = q->next;
                    free(q);
                } else {
                    p = p->next;
                }
            }
        }
        return head;
    }
};