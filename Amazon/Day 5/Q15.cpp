// https://practice.geeksforgeeks.org/problems/delete-n-nodes-after-m-nodes-of-a-linked-list/1/
// Sol :- https://practice.geeksforgeeks.org/viewSol.php?subId=7795828bde898fc841cf2632b8ced6d0&pid=700021&user=2019kucp1053
//  time :- O(no of nodes) Space:- O(1)

 void linkdelete(struct Node  *head, int M, int N)
    {
        //Add code here   
        Node* p = head, *prev;
        int cnt = 0;
        while(p){
            cnt = 0;
            while(cnt<M && p){
                cnt++;
                prev = p;
                p = p->next;
            }
            if(cnt<M) break;
            
            cnt = 0;
            while(p && cnt<N){
                cnt++;
                p = p->next;
            }
            
            prev->next = p;
            
        }
        
        return ;
    }
