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

    private:

    int getLength(ListNode* head){
        ListNode* temp = head;
        int count=0;

        while(temp != NULL){
            temp = temp->next;
            count++;
        }

        return count;
    }

    int getPower (int val){
        int res = 1;
        for(int i=0; i<val; i++){
            res *= 2; 
        }
        return res;
    }

public:
    int getDecimalValue(ListNode* head) {

        int len = getLength(head);
        int res = 0;

        ListNode* temp = head;

        while(temp != NULL){
            if(temp->val){
                res += getPower(len-1);
            }
            len--;
            temp = temp->next;
        }

        return res;
        
    }
};