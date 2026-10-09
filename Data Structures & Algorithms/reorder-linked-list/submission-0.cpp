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
    void reorderList(ListNode* head) {
        //step-1: Find Middle Point
        //step-2: Reverse the Second half 
        //step-3: Merge the 2 halves like this first take one from first half then
        //take first from second half, second from first half, second from second   half


        //find middle point
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast != nullptr and fast->next != nullptr){
            slow = slow -> next;
            fast = fast->next->next;
        }

        

        //reverse the second half
        ListNode* prev = nullptr;
        ListNode* cur = slow->next;
        slow->next = nullptr;

        while(cur != nullptr){
            //save 
            ListNode* nxt = cur->next;
            //flip
            cur->next = prev;
            //move
            prev = cur;
            cur = nxt;
        }
        ListNode* head2 = prev;
        ListNode dummy(0);
        ListNode* node = &dummy;

        while(head and head2){
          ListNode* next1 = head->next;
          ListNode* next2 = head2->next;

          node->next = head;
          node = node->next;

          node->next = head2;
          node = node->next;

          head = next1;
          head2 = next2;
        }
        if(head) node->next = head;
        else node -> next = head2;

        


    }
};
