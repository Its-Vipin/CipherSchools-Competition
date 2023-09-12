class Solution {
public:
    int sizeOfLinkedList(ListNode* head) {
        int size = 0; 
        while (head != NULL) {
            size++;
            head = head->next;
        }
        return size;
    }

    ListNode* reverse(ListNode* &head) {
        ListNode* prev = NULL;
        ListNode* current = head;
        while (current != NULL) {
            ListNode* next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
        return head;
    }

    int pairSum(ListNode* head) {
        int x = sizeOfLinkedList(head);
        if (x < 2) {
            return 0; 
        }
        
        ListNode* head2 = head;
        for (int i = 0; i < (x / 2); i++) {
            head2 = head2->next;
        }

        reverse(head2);

        int maxSum = head->val + head2->val;
        head = head->next;
        head2 = head2->next;

        while (head != NULL && head2 != NULL) {
            int sum = head->val + head2->val;
            maxSum = max(maxSum, sum);
            head = head->next;
            head2 = head2->next;
        }

        return maxSum;
    }
};
