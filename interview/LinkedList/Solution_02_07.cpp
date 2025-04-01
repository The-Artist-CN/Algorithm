

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr){
            return nullptr;
        }
        unordered_set<ListNode*> seen;
        ListNode* temp = headA;
        while (temp != nullptr){
            seen.insert(temp);
            temp = temp->next;
        }

        temp  = headB;

        while (temp != nullptr){
            if (seen.count(temp)){
                return temp;
            }
            temp = temp->next;
        }

        return nullptr;
    }

    ListNode *getIntersectionNodeV2(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return nullptr;
        
        ListNode *a = headA, *b = headB;
        
        // When a reaches end of list, redirect to headB, and vice versa
        // If there's an intersection, they'll meet at the intersection point
        // If not, they'll both reach nullptr at the same time
        while (a != b) {
            a = a ? a->next : headB;
            b = b ? b->next : headA;
        }
        
        return a;
    }
};
