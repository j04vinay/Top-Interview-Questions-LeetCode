/* You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // if first list is empty
        if(list1==NULL)
            return list2;
        
        // if second list is empty
        if(list2==NULL)
            return list1;
        
        // if value of list1 is greater than list2 then do recusive call
        if(list1->val > list2->val){
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }else{
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }
    }
};