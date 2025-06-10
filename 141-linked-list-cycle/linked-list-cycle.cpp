/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        ListNode* tortoise = head;
        ListNode* rabbit = head;

        while(rabbit != NULL && rabbit->next != NULL ){
            
            tortoise = tortoise->next;
            rabbit = rabbit->next->next;

            if(tortoise == rabbit){
                return true;
            }
        }

        return false;
    }
};