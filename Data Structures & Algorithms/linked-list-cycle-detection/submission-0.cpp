
class Solution {
public:
    bool hasCycle(ListNode* head)
    {
        auto fast = head;
        auto slow = head;

        while (true)
        {
            if (fast == nullptr || fast->next == nullptr) {
                return false;
            }

            fast = fast->next->next;
            slow = slow->next;

            if (fast == slow) {
                return true;
            }
        }
    }
};
