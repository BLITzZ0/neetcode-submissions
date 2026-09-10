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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * ans_head = new ListNode((l1-> val +  l2 -> val) % 10);
        int carry = (l1 -> val + l2 -> val) / 10;
        l1= l1 -> next;
        l2 = l2 -> next;

        ListNode * temp = ans_head;

        while(l1 != nullptr || l2  != nullptr || carry){
            int n1 = (l1 != nullptr) ? l1 -> val : 0;
            int n2 = (l2 != nullptr) ? l2 -> val : 0;

            int sum = n1 + n2 + carry;
            int digit = sum % 10;
            

            ListNode * curr = new ListNode(digit);
            temp->next = curr;
            temp = temp -> next;

            if(l1 != nullptr)l1 = l1 -> next;
            if(l2 != nullptr)l2 = l2 -> next;
            carry = sum / 10;
        }
    
        return ans_head;
        
    }
};
//1,2,3
//4,5,6
//5,7,9

//9,9,9
//0,0,1
//0,0,0,1

//9
//9
//8, 1