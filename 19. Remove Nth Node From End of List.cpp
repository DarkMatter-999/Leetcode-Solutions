class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fast = head, *slow = head;
        for (int i = 0; i < n; i++)
            fast = fast->next;
        
        if (!fast)
            return head->next;

        while (fast->next) {
            fast = fast->next;
            
            slow = slow->next;
        }
        ListNode* del = slow->next;
        slow->next = slow->next->next;
        delete(del);
        
        return head;
    }

};
