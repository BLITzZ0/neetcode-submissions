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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        // if(n == 1)return nullptr;
        int count = 1;
        ListNode *temp = head;

        while(temp != nullptr){
            count++;
            temp = temp -> next;
        }

        int target = count - n;
        if(target == 1){
            ListNode *next = head -> next;
            delete(head);
            return next;
        }
        temp = head;
        ListNode *prev = nullptr;

        int i = 1;
        while(temp){
            ListNode *next = temp -> next;
            
            if(i == target){
                prev->next = next;
                delete(temp);
                break;
            }

            i++;
            prev= temp;
            temp = temp ->next;
        }
        return head;
    }
};
