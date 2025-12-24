struct ListNode* middleNode(struct ListNode* head) {
    int count = 0;
    struct ListNode* temp = head;

    // First pass: count nodes
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    // Second pass: go to middle
    int midIndex = count / 2;
    temp = head;
    for (int i = 0; i < midIndex; i++) {
        temp = temp->next;
    }

    return temp;
}
