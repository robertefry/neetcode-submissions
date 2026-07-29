
class Solution {
public:
    ListNode* reverseList(ListNode* head)
    {
        auto prev = (ListNode*)nullptr;
        auto curr = head;

        while (curr != nullptr) {
            auto next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};
