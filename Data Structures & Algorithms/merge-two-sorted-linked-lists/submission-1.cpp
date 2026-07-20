
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        if (list1 == nullptr) {
            return list2;
        }
        if (list2 == nullptr) {
            return list1;
        }

        auto const take_next = [&]()
        {
            if (list1->val < list2->val) {
                auto const node = list1;
                list1 = list1->next;
                return node;
            } else {
                auto const node = list2;
                list2 = list2->next;
                return node;
            }
        };

        auto const head = take_next();
        auto curr = head;

        while (list1 != nullptr && list2 != nullptr) {
            curr->next = take_next();
            curr = curr->next;
        }

        if (list1 == nullptr) {
            curr->next = list2;
        }
        if (list2 == nullptr) {
            curr->next = list1;
        }

        return head;
    }
};
