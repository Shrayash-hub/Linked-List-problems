/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* findMiddle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head->next;  // Fix: Start fast at head->next

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow; // Returns the first middle node in even-length lists
    }

    // Merge two sorted linked lists
    ListNode* mergeTwoSortedLinkedLists(ListNode* list1, ListNode* list2) {
        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;

        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                temp->next = list1;
                list1 = list1->next;
            } else {
                temp->next = list2;
                list2 = list2->next;
            }
            temp = temp->next; 
        }

        // Append remaining elements
        temp->next = (list1 != nullptr) ? list1 : list2;

        return dummyNode->next;
    }

    // Merge sort implementation for linked list
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head; // Base case: already sorted
        }

        ListNode* middle = findMiddle(head);
        ListNode* right = middle->next;
        middle->next = NULL; // Split the list into two halves
        ListNode* left = head;

        left = sortList(left);   // Sort left half
        right = sortList(right); // Sort right half

        return mergeTwoSortedLinkedLists(left, right); // Merge sorted halves
    }
};