
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // if head is NULL return NULL 
        if(head == NULL){
            return head ; 
        }

        ListNode* temp = head ;
        int count = 1 ;  
        // count the number of elements in LinkedList 
        while(temp->next != NULL ){
            temp = temp->next ;
            count++;
        }
        // cout << count << " "; 

        if(count == 1){
            //if there is only head and after deletion of head it will point to head 
            // head = head->next (i.e head == NULL )
            // you can also return head after pointing head = head->next 
            return NULL ; 
        }
        //iterate through LL to the point before the node you have to delete 
        int itert = count - n ;
        int cnt = 1 ;        
        ListNode* temp1 = head ;
        if(itert == 0){
            //if cnt - n == 0 then you have to delete head 
            //for deleting head we will assign head to its next point 
            head = head->next;
            return head ; 
            
        } 
        // get the one node before the target node 
        while(itert != cnt && temp1->next != NULL ){      
            temp1 = temp1->next; 
            cnt++;
        }
        cout << "cnt : " << cnt ; 
        cout << endl ; 
        cout << temp1->val; 
        
        temp1->next = temp1->next->next; 
        
        return head; 

    }
};