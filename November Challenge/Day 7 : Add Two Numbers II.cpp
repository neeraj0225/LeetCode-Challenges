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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int i,j,k,r;
        stack<int> s1,s2;
        ListNode* temp1=l1,*temp2=l2;
        while(temp1!=NULL || temp2!=NULL)
        {
            if(temp1)
            { 
                s1.push(temp1->val);
                temp1 = temp1->next;
            }
            if(temp2)
            {
                s2.push(temp2->val);
                temp2 = temp2->next;
            }
        }
        k = 0;
        ListNode *prev = NULL;
        while(!s1.empty() || !s2.empty())
        {
            i=0;j=0;
            if(!s1.empty())
            {
                i = s1.top();
                s1.pop();
            }
            if(!s2.empty())
            {
                j = s2.top();
                s2.pop();
            }
            int sum = i + j + k;
            r = sum%10;
            k = sum/10;
            ListNode *temp = new ListNode(r);
            temp->next = prev;
            prev = temp;
        }
        if(k > 0)
        {
            ListNode *temp = new ListNode(k);
            temp->next = prev;
            prev = temp;
        }
        return prev;
    }
};
