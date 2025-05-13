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

    ListNode* getMiddle(ListNode* &head, ListNode* &middleNodeKaPrev){
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL){
            fast=fast->next;
             if(fast!=NULL){
                fast=fast->next;
                middleNodeKaPrev = slow;
                slow=slow->next;
             }
        }
        return slow;
    }

    ListNode* Reverse(ListNode* &prev, ListNode* &curr){
        while(curr!=NULL){
            ListNode* forward = curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {

        if(head == NULL){
            //LL is empty
            return true;
        }
        if(head->next==NULL){
            //single node
            return true;
        }

        //traverse till middle node and break LL in 2
        ListNode* firstHalfHead = head;
        ListNode* middleNodeKaPrev = NULL;
        ListNode* middleNode = getMiddle(head, middleNodeKaPrev);
        
        //break
        if (middleNodeKaPrev != NULL) {
            middleNodeKaPrev->next = NULL;
        } else {
            //for 2 node case, break from head
            head = NULL;
        }

        //reverse 2nd half of LL
        ListNode* prev = NULL;
        ListNode* curr = middleNode;
        ListNode* secondHalfHead = Reverse(prev,curr);

        //compare both the halves and decide T/F
        //even length waale case mai dono half ki length euqal hogi
        //odd waale case mai 2nd half ki len badi hogi by 1
        //thats whu comparison 1st half ke hisab se hoga
        ListNode* temphead1 = firstHalfHead;
        ListNode* temphead2 = secondHalfHead;
        while(temphead1 != NULL){
            if(temphead1->val != temphead2->val){
                //not a palindrome
                return false;
            }
            else{
                //data equal hai toh dono ko aage badhao
                temphead1 = temphead1->next;
                temphead2 = temphead2->next;
            }
        }
        //yaha tak pahocha mtlb palindrome hai 
        return true;
        
    }
};
