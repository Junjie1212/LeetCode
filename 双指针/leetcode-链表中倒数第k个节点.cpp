/**
输入一个链表，输出该链表中倒数第k个节点。为了符合大多数人的习惯，本题从1开始计数，即链表的尾节点是倒数第1个节点。

示例：
给定一个链表: 1->2->3->4->5, 和 k = 2.
返回链表 4->5.
 */
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* slow = head;
        ListNode* fast = head;
        int count = 1;
        while(fast!=NULL)
        {
            if(fast->next!=NULL && (fast->next->next) != NULL)
            {
                fast = fast->next->next;
                count+=2;
            }
            else if(fast->next!=NULL)
            {
                fast = fast->next;
                count+=1;
            }
            else
                fast = fast->next;
        }
        int zz = count-k;
        while(zz--)
            slow = slow->next;
        return slow;
    }
};
