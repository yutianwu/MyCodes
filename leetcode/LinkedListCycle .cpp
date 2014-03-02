/*
Linked List Cycle
Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?
分析：
我们的问题就是，如何检测一个链表中是否有环，如果检测到环，如何确定环的入口点（即求出环长，环前面的链长）。
一种比较耗空间的做法是，从头开始遍历链表，把每次访问到的结点（或其地址）存入一个集合（hashset）或字典（dictionary），
如果发现某个结点已经被访问过了，就表示这个链表存在环，并且这个结点就是环的入口点。这需要O(N)空间和O(N)时间，其中N是
链表中结点的数目。


如果要求只是用O(1)空间、O(N)时间，应该怎么处理呢？

其实很简单，想象一下在跑道上跑步：两个速度不同的人在操场跑道上一圈一圈地跑，他们总会有相遇的时候。
因此我们只需要准备两个指针，同时从链表头出发，一个每次往前走一步，另一个每次往前走两步。如果链表
没有环，那么经过一段时间，第二个（速度较快的）指针就会到达终点；但如果链表中有环，两个指针就会在
环里转圈，并会在某个时刻相遇。
*/

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
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                return true;
            }
        }
        return false;
    }
};