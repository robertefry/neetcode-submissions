
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        constexpr auto takeHead = [](ListNode** head) -> ListNode*
        {
            auto const node = *head;
            *head = node->next;
            return node;
        };

        constexpr auto mergeTwoLists = [=](ListNode* list1, ListNode* list2) -> ListNode*
        {
            if (list1 == nullptr) {
                return list2;
            }
            if (list2 == nullptr) {
                return list1;
            }

            auto const head = takeHead((list1->val < list2->val) ? &list1 : &list2);
            auto curr = head;

            while (list1 != nullptr && list2 != nullptr) {
                curr->next = takeHead((list1->val < list2->val) ? &list1 : &list2);
                curr = curr->next;
            }

            if (list1 == nullptr) {
                curr->next = list2;
            }
            if (list2 == nullptr) {
                curr->next = list1;
            }

            return head;
        };

        if (lists.empty()) {
            return nullptr;
        }

        auto head = lists[0];

        for (auto i = 1; i < lists.size(); ++i) {
            head = mergeTwoLists(head, lists[i]);
        }
        return head;
    }
};
