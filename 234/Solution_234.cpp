#include <iostream>
#include "ListNode_CPP.h"
#include <stack>

using namespace std;

class Solution {
public:
    bool isPalindromeUseStack(ListNode* head){
        stack<int> st;

        ListNode* p = head;

        while(p!=nullptr){
            st.push(p->val);
            p = p->next;
        }

        p = head;

        while( !p ){
            if (p->val != st.top()){
                return false;
            }
            st.pop();
            p = p->next;
        }

        return true;
    }
};


// 测试代码
int main() {
    // 示例链表: 1 -> 2 -> 2 -> 1
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);

    Solution solution;
    bool result = solution.isPalindromeUseStack(head);
    cout << (result ? "true" : "false") << endl; // 输出: true

    // 释放链表内存
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
