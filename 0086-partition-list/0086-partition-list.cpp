class Solution {
public:
    ListNode* partition(ListNode* head, int x) {

        ListNode* lessDummy = new ListNode(0);
        ListNode* greaterDummy = new ListNode(0);

        ListNode* less = lessDummy;
        ListNode* greater = greaterDummy;

        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* nextNode = curr->next;
            curr->next = nullptr;

            if (curr->val < x) {
                less->next = curr;
                less = less->next;
            }
            else {
                greater->next = curr;
                greater = greater->next;
            }

            curr = nextNode;
        }

        less->next = greaterDummy->next;

        ListNode* result = lessDummy->next;

        delete lessDummy;
        delete greaterDummy;

        return result;
    }
};