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
    ListNode* reverseKGroup(ListNode* head, int k) {
        auto p=head;
        int len=0;
        while(p!=NULL && len<k)
        {
            p=p->next;
            len++;
        }
        if(len<k)
            return head;//不足k个的
        
        ListNode* prev=NULL;//头插法
        auto cur=head;
        while(cur!=p)
        {
            auto Next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=Next;
        }
        head->next=reverseKGroup(p,k); //反转后当初的头节点便是尾节点了
        return prev;//而被cur赋值的prev便成为了头节点
    }
};