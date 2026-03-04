struct ListNode* mergeTwo(struct ListNode* l1, struct ListNode* l2){
    struct ListNode dummy;
    struct ListNode* tail = &dummy;
    dummy.next = NULL;

    while(l1 && l2){
        if(l1->val < l2->val){
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    if(l1) tail->next = l1;
    if(l2) tail->next = l2;

    return dummy.next;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    if(listsSize == 0) return NULL;

    while(listsSize > 1){
        int i = 0, j = listsSize - 1;

        while(i < j){
            lists[i] = mergeTwo(lists[i], lists[j]);
            i++;
            j--;
        }

        listsSize = (listsSize + 1) / 2;
    }

    return lists[0];
}
