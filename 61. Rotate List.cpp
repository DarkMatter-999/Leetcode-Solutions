// O(n) O(1)
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if( !head || !head->next || k==0){
            return head;
        }

        ListNode* ohead = head;
        int len=1;

        while(ohead->next){
            ohead=ohead->next;
            len++;
        }

        ohead->next = head;
        k = k%len;
        k = len - k;

        while(k--){
            ohead=ohead->next;
        }

        head = ohead->next;
        ohead->next = NULL;

        return head;

    }
};

// Two Pointers
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || k == 0) {
            return head;
        }

        int len = length(head);
        k %= len;

        if (k == 0) {
            return head;
        }

        ListNode* fast = head;
        ListNode* slow = head;

        for(int i=0; i<k; i++) {
            if(fast) {
                fast = fast->next;
            } else {
                return head;
            }
        }

        while(fast->next) {
            fast = fast->next;
            slow = slow->next;
        }

        ListNode* neww = slow->next;
        slow->next = nullptr;
        fast->next = head;

        return neww;
    }

    int length(ListNode* head) {
        int len = 0;
        while (head) {
            len++;
            head = head->next;
        }
        return len;
    }
};
