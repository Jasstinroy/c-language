struct ListNode* reverse(struct ListNode* head, int k) {
    struct ListNode *prev = NULL, *next = NULL;
    int count = 0;

    while (head != NULL && count < k) {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
        count++;
    }

    return prev;
}

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    struct ListNode *temp = head;
    int count = 0;

    while (temp != NULL && count < k) {
        temp = temp->next;
        count++;
    }

    if (count < k)
        return head;

    struct ListNode* newHead = reverse(head, k);

    head->next = reverseKGroup(temp, k);

    return newHead;
}
