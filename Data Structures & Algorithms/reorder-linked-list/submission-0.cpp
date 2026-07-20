
class Solution {
public:
    void reorderList(ListNode* head)
    {
        // assumption: the list is acyclic

        // 1. find the mid-point using fast/slow
        // 2. reverse the second half
        // 3. merge

        constexpr auto split = [](ListNode* head) -> ListNode*
        {
            auto fast = head;
            auto slow = head;

            while (fast != nullptr && fast->next != nullptr) {
                fast = fast->next->next;
                slow = slow->next;
            }

            fast = slow->next;
            slow->next = nullptr;

            return fast;
        };

        constexpr auto reverse = [](ListNode* head) -> ListNode*
        {
            auto curr = head;
            auto prev = (ListNode*)nullptr;

            while (curr != nullptr) {
                auto next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            return prev;
        };

        auto list1 = head;
        auto list2 = reverse(split(head));

        while (list1 != nullptr && list2 != nullptr) {
            auto tmp = list2->next;
            list2->next = list1->next;
            list1->next = list2;
            list1 = list2->next;
            list2 = tmp;
        }
    }
};
