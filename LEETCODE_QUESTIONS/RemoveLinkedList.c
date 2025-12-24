/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* removeElements(struct ListNode* head, int val) {
    while (head != NULL && head->val == val) {
        struct ListNode* toDelete = head;
        head = head->next;
        free(toDelete);
    }

    struct ListNode* temp = head;

    while (temp != NULL && temp->next != NULL) {
        if (temp->next->val == val) {
            struct ListNode* toDelete = temp->next;
            temp->next = temp->next->next;
            free(toDelete);
        } else {
            temp = temp->next;
        }
    }

    return head;
}
