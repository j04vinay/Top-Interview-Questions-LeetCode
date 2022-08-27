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
        
        /* Method 1 : Using efficient method
        we are initializing result pointer and current pointer 
        then traversing both linked list until there is no element left.
        */
        int sum = 0;
        ListNode result(0);
        ListNode *current = &result;
        while(l1 || l2){
            if(l1){
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2){
                sum += l2->val;
                l2 = l2->next;
            }
            
            current->next = new ListNode(sum%10);
            current = current->next;
            sum = sum/10;
        }
        if(sum>0){
            current->next = new ListNode(sum%10);
        }
        return result.next;
    }
};