class Solution {
public:
    ListNode* getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> us;
        ListNode *temp = headA;
        while (temp != nullptr) {
            us.insert(temp);
            temp = temp->next;
        }

        temp = headB;
        while (temp != nullptr) {
            if (us.count(temp)) return temp;
            temp = temp->next;
        }
        return nullptr;
    }

    ListNode* getIntersectionNode_Better(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) return nullptr;
        ListNode *A = headA, *B = headB;
        while (A != B) {
            A = (A != nullptr) ? A->next : headB;
            B = (B != nullptr) ? B->next : headA;
        }
        return A;
    }
};
