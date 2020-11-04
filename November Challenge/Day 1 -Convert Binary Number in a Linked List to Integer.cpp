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
    int getDecimalValue(ListNode* head) {
        int n=0,i=0,j=1;
        ListNode *temp = head;
        while(temp!=NULL)
        {
            n++;
            temp = temp->next;
        }
        temp = head;
        n--;
        while(temp!=NULL && n>=0)
        {
            j=1;
            if(temp->val == 1)
            {
                i+= j<<n;   
            }
            temp = temp->next;
            n--;
        }
        return i;
    }
};
