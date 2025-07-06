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
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode*, bool> m;
        ListNode* temp = head;
        while(temp!=NULL){
            if(m[temp]==true){
                return temp;
            }
            else{
                m[temp]=true;
            }
            temp=temp->next;
        }
        return nullptr;
    }
};