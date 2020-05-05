/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //快排思想，选一个中间值做基础 小于的链到小的链上left  等于的链到等于的链上mid   大于的链到大于的链上right
class Solution {
public:
    ListNode* get_tail(ListNode* head)
    {
        while(head->next)
            head=head->next;
        return head;
    }
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        int val=head->val;
        auto left=new ListNode(-1),mid=new ListNode(-1),right=new ListNode(-1);//头
        auto ltail=left,mtail=mid,rtail=right;//尾
        auto cur=head;
        while(cur)//快排划分
        {
            if(cur->val<val)
                ltail=ltail->next=cur;
            else if(cur->val==val)
                mtail=mtail->next=cur;
            else
                rtail=rtail->next=cur;
            cur=cur->next;
        }
        ltail->next=NULL;//结尾，不然可能会因为没有断链而乱了
        mtail->next=NULL;
        rtail->next=NULL;
        //分治 递归
        left->next=sortList(left->next);
        right->next=sortList(right->next);
        //链接
        get_tail(left)->next=mid->next;
        get_tail(left)->next=right->next;
        return left->next;
    }
};