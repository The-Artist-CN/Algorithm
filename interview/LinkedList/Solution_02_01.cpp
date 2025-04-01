#include <iostream>
#include <unordered_set>
#include <vector>
#include "ListNode_CPP.h"


ListNode* removeDuplicate(ListNode* head);
ListNode* removeDuplicateNode_v2(ListNode* head);
ListNode* createLinkedList(std::vector<int>& array);
void printLinkedList(ListNode* head);

int main() {
    // 示例1
    std::vector<int> arr1 = {1, 2, 3, 3, 2, 1};
    ListNode* head1 = createLinkedList(arr1);
    head1 = removeDuplicate(head1);
    printLinkedList(head1); // 输出: 1 2 3

    // 示例2
    std::vector<int> arr2 = {1, 1, 1, 1, 2};
    ListNode* head2 = createLinkedList(arr2);
    head2 = removeDuplicateNode_v2(head2);
    printLinkedList(head2); // 输出: 1 2

    return 0;
}

ListNode* removeDuplicate(ListNode* head) {
    if (!head) return head;

    std::unordered_set<int> us;
    us.insert(head->val);
    ListNode* current = head;

    while (current->next) {
        if (us.find(current->next->val) != us.end()) {
            ListNode* temp = current->next;
            current->next = current->next->next;
            delete temp; // 释放内存
        } else {
            us.insert(current->next->val);
            current = current->next;
        }
    }

    return head;
}

ListNode* createLinkedList(std::vector<int>& array) {
    int n = array.size();
    if (n == 0) return nullptr;
    ListNode* head = new ListNode(array[0]);
    ListNode* current = head;
    for (int i = 1; i < n; i++) {
        current->next = new ListNode(array[i]);
        current = current->next;
    }
    return head;
}

void printLinkedList(ListNode* head) {
    ListNode* current = head;
    while (current) {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

// Apr 1 13:00PM


ListNode* removeDuplicateNode_v2(ListNode* head){
    if (head == nullptr){
        return nullptr;
    }

    ListNode* current = head;
    ListNode* prev = nullptr;
    std::unordered_set<int> seen;

    while (current){
        if (seen.find(current->val) != seen.end()){
            prev->next = current->next;
            delete current;
            current = prev->next;
        } else {
            seen.insert(current->val);
            prev = current;
            current = current->next;
        }
    }

    return head;
}
