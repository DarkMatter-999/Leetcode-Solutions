class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* groupPrev = dummy;

        while(true) {
            ListNode* kth = getKth(groupPrev, k);
            if (!kth) {
                break;
            }
            ListNode* groupNext = kth->next;
            ListNode* prev = kth->next;
            ListNode* curr = groupPrev->next;

            while(curr != groupNext) {
                ListNode* tmp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = tmp;
            }

            ListNode* tmp = groupPrev->next;
            groupPrev->next = kth;
            groupPrev = tmp;
        }

        return dummy->next;
    }

    ListNode* getKth(ListNode* node, int k) {
    while(node && k>0) {
        node = node->next;
        k--;
    }
    return node;
    }
};
