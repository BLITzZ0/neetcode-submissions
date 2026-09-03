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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr) return list2;
        if(list2 == nullptr) return list1;
        
        ListNode *left = list1;
        ListNode *right = list2;

        ListNode *head;
        if(left -> val <= right -> val){
            head = left;
            left = left -> next;
        }
        else{
            head = right;
            right = right -> next;
        }
        ListNode *temp = head; 

        while(left != nullptr && right != nullptr){
            if(left -> val <= right -> val){
                temp->next = left;
                left = left -> next;
            }
            else{
                temp -> next = right;
                right = right -> next;
            }
            temp = temp -> next;
        }

        if(left != nullptr)temp->next = left;
        else temp -> next = right;

        return head;
    }
};
