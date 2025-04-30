class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        vector<int> values;
        ListNode *curr = head;
        while (curr != nullptr) {
            values.push_back(curr->val);
            curr = curr->next;
        }
        reverse(values.begin(), values.end()); // 反转值
        return createNewList(values);
    }

    ListNode* createNewList(vector<int>& nums) {
        if (nums.empty()) return nullptr;
        ListNode *dummy = new ListNode(0); // 虚拟头节点
        ListNode *curr = dummy;
        for (int num : nums) {
            curr->next = new ListNode(num);
            curr = curr->next;
        }
        return dummy->next; // 返回真实头节点
    }

    ListNode* reverseList_Better(ListNode* head){
        ListNode *cur = head;
        ListNode *pre = nullptr;
        while (cur){
            ListNode *next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};
