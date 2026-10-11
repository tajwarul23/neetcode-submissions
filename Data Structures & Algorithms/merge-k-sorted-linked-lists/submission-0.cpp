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
    /**
     * suppose a is the new value, and b is the old value, we are comparing a and b
     * if the condition is true a will go deep in the queue
     * if the condition is false a will stay on the top
     * so the core logic here is if the condition is true newer value will go to the deep
     */
    struct compareNodes {
        bool operator()(const ListNode* const& a, const ListNode* const& b) { return a->val > b->val; }
    };
    
     ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (!lists.size()) return nullptr;
        priority_queue<ListNode*, vector<ListNode*>, compareNodes> minHeap;

        for (ListNode* list : lists) {
            if (list != nullptr) minHeap.push(list);
        }

        ListNode dummy(0);
        ListNode* cur = &dummy;

        while(!minHeap.empty()){
            ListNode* node = minHeap.top();
            minHeap.pop();
            cur->next = node;
            cur = cur->next;

            node = node->next;
            if(node != nullptr){
                minHeap.push(node);
            }
        }

        return dummy.next;
    }
};
