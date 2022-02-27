void AddNode(ListNode* node1, ListNode* node2){
    node2->next = node1->next; 
    node1->next = node2;
 }

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        //protect head for list2
        ListNode* protectHead = new ListNode();
        protectHead->next = list2;
        list2 = protectHead;
        while(list1 != nullptr){
            if((list2->next == nullptr) || (list1->val < list2->next->val)){
                ListNode* nextList1 = list1->next; //buff list1.next
                AddNode(list2, list1);  //update list2 content
                list1 = nextList1;  //update list1 ptr
            }
            list2 = list2->next;    //update list2 ptr        
        }
        return protectHead->next;
    }
};