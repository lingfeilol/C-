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
    ListNode* sortList(ListNode* head) {
        if(!head||!head->next) return head;
        auto slow=head,fast=head;
        while(!fast&&!fast->next) //找中间节点
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        auto tmp=slow->next;//分割两条链，准备划分
        slow->next=NULL;
        auto left=sortList(head);//划分
        auto right=sortList(tmp);
        //归并
        auto newhead=new ListNode(0);
        auto cur=newhead;
        while(left && right)
        {
            if(left->val<right->val)
            {
                cur->next=left;
                left=left->next;
            }
            else
            {
                cur->next=right;
                right=right->next;
            }
            cur=cur->next;
        }
        cur->next= left==NULL? right:left;
        return newhead->next;
    }
};