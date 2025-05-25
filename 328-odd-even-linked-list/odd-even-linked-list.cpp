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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL){
            return NULL;
        }
        if(head->next==NULL){
            return head;
        }
        ListNode *temp = head;
        ListNode *temp2 = NULL;
        ListNode *listOne = head;
        ListNode *listTwo = head->next;
        while(temp->next!=nullptr && temp->next->next!=nullptr){
            temp2 = temp->next;
            temp->next = temp->next->next;
            temp=temp2;
        }
        temp->next = nullptr;
        ListNode *add = listOne;
        while(add->next!=NULL){
            add= add->next;
        }
        add->next = listTwo;
        return head;
    }
};