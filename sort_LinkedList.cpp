/**
 * Link: https://www.nowcoder.com/practice/d75c232a0405427098a8d1627930bea6?tpId=46&tqId=29033&tPage=1&rp=1&ru=/ta/leetcode&qru=/ta/leetcode/question-ranking
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/**
 * findMiddle方法在没有头结点的链表中寻找中间结点；
 * 如果是带有头结点的链表，记得是初始化时，slow指向第一个，fast指向第二个。
 * 即改为slow=head->next;fast=head->next->next;
 */

class Solution {
public:
    ListNode* findMiddle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next; //慢的走一步
            fast = fast->next->next; //快的走两步
        }
        return slow;
    }
     
 ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL){
            return l2;
        }
        if(l2 == NULL){
            return l1;
        }
        ListNode* dummy = new ListNode(0);
        ListNode* head = dummy;
        while(l1 != NULL && l2 != NULL){
            if(l1->val > l2->val){
                head->next = l2;
                l2 = l2->next;
            }
            else{
                head->next = l1;
                l1 = l1->next;
            }
            head = head->next;
        }
        if(l1 == NULL){
            head ->next = l2;
        }
        if(l2 == NULL){
            head->next = l1;
        }
        return dummy->next;
    }
     
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head ->next == NULL){
            return head;
        }
        ListNode* middle = findMiddle(head);
        ListNode* right = sortList(middle->next);
        middle -> next = NULL;
        ListNode* left = sortList(head);
        return mergeTwoLists(left, right);
    }
};