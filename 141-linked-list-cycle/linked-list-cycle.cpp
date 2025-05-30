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
        ListNode* slow= head;
        ListNode* fast=head;
        while(fast!=NULL){
            fast=fast->next;
            if(fast!=NULL){
                fast=fast->next;
                slow=slow->next; 
                if(fast==slow){
                    //at some point fast=slow if there is a cycle  
                    //cycle present hai 
                    return true;
                }
            }

        }
        return false;




        //METHOD 1 using map
        // unordered_map<ListNode* , bool> m;
        // ListNode* temp = head;

        // while(temp!=NULL){
        //     if(m[temp]==true){
        //         //pahale se he true hai 
        //         //cycle present hai 
        //         return true;
        //     }
        //     else{
        //         //pahale se true nhi hai mtlb false hai 
        //         //true krna pdega 
        //         m[temp]=true;
        //     }
        //     temp = temp->next;
        // }
        // //puri LL traverse ho chuki hai 
        // return false; 

        
    }
};