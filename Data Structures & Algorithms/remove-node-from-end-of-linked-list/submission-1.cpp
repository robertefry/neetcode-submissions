
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        // assumption: there are at least n elements in the list

        auto fast = head;
        auto slow = head;

        for (int i = 0; i < n; ++i) {
            fast = fast->next;
        }

        if (fast == nullptr) {
            return head->next;
        }
        fast = fast->next;

        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        // TODO: debug_assert(slow->next != nullptr)
        slow->next = slow->next->next;
        return head;
    }
};
