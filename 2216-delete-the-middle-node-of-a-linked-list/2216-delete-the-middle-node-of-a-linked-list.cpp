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
    ListNode* deleteMiddle(ListNode* head) {

        if (!head->next) return nullptr;

        ListNode* trav = head; 
        int n = 0;
        while(trav!=nullptr){
            n++; 
            trav = trav->next;
        }

        int i = 0; 
        int mid = n/2;
        trav = head; 

        while(i<mid-1){
            trav = trav->next; 
            i++;
        }

        trav->next = trav->next->next; 

        return head;
        
    }
};