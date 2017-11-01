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
    /*
     * @param l1: the first list
     * @param l2: the second list
     * @return: the sum list of l1 and l2 
     */
    
    ListNode * addLists(ListNode * l1, ListNode * l2) {
        return addLists(l1, l2, 0);
    }
    
    ListNode * addLists(ListNode * l1, ListNode * l2, int c) {
        if (l1 == NULL && l2 == NULL && c == 0)
            return NULL;
        if (l1 != NULL) {
            c += l1->val;
            l1 = l1->next;
        }
        if (l2 != NULL) {
            c += l2->val;
            l2 = l2->next;
        }
        ListNode * ans = new ListNode(c % 10);
        ans->next = addLists(l1, l2, c / 10);
        return ans;
    }
};