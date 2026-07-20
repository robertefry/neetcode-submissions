
class Solution {
public:
    bool hasCycle(ListNode* head)
    {
        auto fast = head;
        auto slow = head;

        while (fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;

            if (fast == slow) {
                return true;
            }
        }
        return false;
    }
};
