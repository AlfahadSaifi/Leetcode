//***************APPROACH**********************************
/*In this problem we are given a head pointer of a singly linked 
list and a integer depicting a value. Here we have to remove the
nth node from the list and return the head of modified list.

Sounds simple enough but the main problem will arise in the 
hidden test case.

During the designing of the program we have to keep some conditions
in mind

*****************CONDITION 1*******************************
we have to check if the length of the list and the value of given
integer is same and is equal to 1

i.e. (length==n && n==1||len==1)

we should return NULL
   
*****************CONDITION 2*******************************  
check if (length==n && (length>1 || n>1))
here we should return head->next node

********************else*********************************** 
we should reach the length-n-1 node and should connect the node
to the node next of next of current node.
***********************************************************

*/




class Solution {
public:
    ListNode *t,*p;
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       int len=0;t=head,p=head;
        while(t->next!=NULL){
            len++;
            t=t->next;
        }
        len=len+1;
        if(n==1 && len==1) return NULL;
        else if(n==len && len>1) {
            return head->next;
        }
        
        else{
        int i=0;
        while(i<len-n-1){
            i++;
            p=p->next;
        }
        p->next=p->next->next;
        return head;    
        }
    }
    
};