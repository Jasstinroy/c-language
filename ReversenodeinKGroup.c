struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    struct ListNode *curr = head, *prev = NULL, *next = NULL;
    int count = 0;

    curr = head;
    while (curr && count < k) {
        curr = curr->next;
        count++;
    }

    if (count == k) {
        curr = head;
        count = 0;

        while (curr && count < k) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        if (next)
            head->next = reverseKGroup(next, k);

        return prev;
    }

    return head;
}
