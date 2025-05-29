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
        unordered_map<ListNode* , bool> m;
        ListNode* temp = head;

        while(temp!=NULL){
            if(m[temp]==true){
                //pahale se he true hai 
                //cycle present hai 
                return temp;
            }
            else{
                //pahale se true nhi hai mtlb false hai 
                //true krna pdega 
                m[temp]=true;
            }
            temp = temp->next;
        }
        //puri LL traverse ho chuki hai 
        return nullptr; 
    }
};