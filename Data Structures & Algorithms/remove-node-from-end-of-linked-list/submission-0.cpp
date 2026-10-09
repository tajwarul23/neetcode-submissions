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
        ListNode* fast = head;
        ListNode* slow = head;

        // move the fast pointer n times
        while (n--) {
            fast = fast->next;
        }

        // The head is the node to delete
        if (fast == nullptr) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        // move slow and fast to find the node before deleting node untill fast hits end
        while (fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        //delete the target node
        ListNode* toDelete = slow->next;
        slow->next = toDelete->next;
        delete toDelete;
        
        return head;
    }
};
