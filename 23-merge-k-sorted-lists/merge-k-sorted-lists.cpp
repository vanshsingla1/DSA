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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>> pq; // min heap -> compares address
        // pair<int,ListNode*>
        ListNode* head = new ListNode(-1);
        ListNode* ptr = head;
        int n = lists.size();
        // vector containing head of lists
        // intially the 1st element of all the lists in pq
        for(int i=0; i<n; i++) {
            if(lists[i] != NULL) pq.push({lists[i]->val,lists[i]});
        }
        // now all the heads of all lists are pushed into pq
        while(!pq.empty()) {
            ListNode *node = pq.top().second;
            pq.pop();
            ptr->next = node;
            node = node->next;
            ptr = ptr->next;
            if(node != NULL) pq.push({node->val,node});
        }
        return head->next;
    }
};