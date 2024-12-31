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
    ListNode* doubleIt(ListNode* head) {
        doubler(head, head);
        return head;
    }

    int doubler(ListNode* &n, ListNode*& h) {
        if (n == nullptr) return 0;
        int val = 2 * n->val + doubler(n->next, h);
        int div = val / 10;
        n->val = val - div * 10;
        if (n == h && div > 0) {
            ListNode *head = new ListNode(div, h);
            h = head;
        }
        return div;
    }
};