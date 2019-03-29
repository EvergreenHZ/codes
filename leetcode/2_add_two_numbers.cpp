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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> v;
        ListNode* p = l1;
        ListNode* q = l2;
        int carry = 0;

        while (p && q) {
            int sum = p->val + q->val + carry;
            v.push_back(sum % 10);
            carry = sum / 10;
            p = p->next;
            q = q->next;
        }

        while (p) {
            v.push_back((p->val + carry) % 10);
            carry = (carry + p->val) / 10;
            p = p->next;
        }
        while (q) {
            v.push_back((q->val + carry) % 10);
            carry = (carry + q->val) / 10;
            q = q->next;
        }

        if (!p && !q && carry) v.push_back(carry);
        ListNode* result = NULL, *t = NULL;
        result = new ListNode(0);
        result->val = v[0];
        t = result;
        for (int i = 1;  i < v.size(); i++) {
            ListNode* node = new ListNode(0);
            node->val = v[i];
            t->next = node;
            t = node;
        }
        return result;
    }
};
