class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> visited;
        ListNode* temp = head;
        while (temp) {
            if (visited.count(temp)) {
                return true;
            }
            visited.insert(temp);
            temp = temp->next;
        }
        return false;
    }
    bool hasCycle_Better(ListNode *head) {
        if (!head) return false;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next){
            if (fast == slow) return true;
            slow = slow->next;
            fast = fast->next->next;
        }
        return false;
    }
};
