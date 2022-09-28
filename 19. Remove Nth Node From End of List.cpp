// 19. Remove Nth Node From End of List
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        ListNode *t = head;
        while(t)
        {
            len++;
            t = t->next;
        }
        n = len - n;
        t = nullptr;
        while(n--)
        {
            if(t == nullptr)
                t = head;
            else
                t = t->next;
        }
        if(t == nullptr)
        {
            head = head->next;
            delete t;
             t = nullptr;
            return head;
        }
        ListNode *temp = t -> next;
        t->next = temp->next;
        delete temp;
        temp = nullptr;
        return head;
    }
};
