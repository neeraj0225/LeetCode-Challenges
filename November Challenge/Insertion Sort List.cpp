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
    ListNode* insertionSortList(ListNode* head) {
        ListNode *curr,*prevCurr,*temp,*prev,*temp2;
        if(head == NULL || head->next == NULL)
            return head;
        else
        {
            int flag;
            prevCurr = head;
            curr = head->next;
            while(curr!=NULL)
            {
                temp = head;prev = NULL;flag=0;
                while(temp!=curr)
                {
                    if(curr->val > temp->val)
                    {
                        prev = temp;
                        temp = temp->next;
                    }
                    else
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag)
                {
                    temp2 = curr->next;
                    if(prev!=NULL)
                        prev->next = curr;
                    curr->next = temp;
                    if(!prev)
                        head = curr;
                    prevCurr->next = temp2;
                    curr = temp2;
                }
                else
                {
                    prevCurr = prevCurr->next;
                    curr = curr->next;
                }
            }
        }
        return head;
    }
};
