
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        vector<int> values;  // 存储所有值
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                values.push_back(list1->val);
                list1 = list1->next;
            } else {
                values.push_back(list2->val);
                list2 = list2->next;
            }
        }
        while (list1 != nullptr) {
            values.push_back(list1->val);
            list1 = list1->next;
        }
        while (list2 != nullptr) {
            values.push_back(list2->val);
            list2 = list2->next;
        }

        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        for (int val : values) {
            curr->next = new ListNode(val);
            curr = curr->next;
        }
        return dummy->next;
    }
    ListNode* mergeTwoLists_Better(ListNode* list1 , ListNode* list2){
        ListNode* preHead = new ListNode(-1);

        ListNode* prev = preHead;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                prev->next = l1;
                l1 = l1->next;
            } else {
                prev->next = l2;
                l2 = l2->next;
            }
            prev = prev->next;
        }

        prev->next = l1 == nullptr ? l2 : l1;

        return preHead->next;

    }
};
