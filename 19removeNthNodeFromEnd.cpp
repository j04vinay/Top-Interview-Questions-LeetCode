/* Given the head of a linked list, remove the nth node from the end of the list and return its head.
*/



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
        // Using two pointer mwthod 
        ListNode *first = head;
        ListNode *last = head;
        int i;
        for(i=0;i<n;i++){
            last = last->next;
        }
        // checking for edge cases
        if(!last){
          return head->next;  
        } 
        while(last->next){
            last = last->next;
            first = first->next;
        }
        // removing nth node
        first->next = first->next->next;
        return head;
        
    }
};