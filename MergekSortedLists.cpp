/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
ListNode* mergeKLists(vector<ListNode*>& lists) {
    ListNode* mergedLists;
    ListNode* head;
    long long k = 0;
    bool doContinue = true;
    while(doContinue){
    	int mn = 1e7 , mnnum = -1;
    	for(long long i = 0; lists.size() > i; i++){
		    if(lists[i] != nullptr && lists[i] -> val < mn){
		    	mn = lists[i] -> val;
		    	mnnum = i;
		    }
		}
		if(mnnum == -1){
			doContinue = false;
		}
		else{
			if(k == 0){
				head = new ListNode(mn);
			}
			else{
				ListNode* newNode = new ListNode(mn);
				ListNode* temp = head;
				while(temp -> next != nullptr){
					//cout << temp -> val << " ";
					temp = temp -> next;
				}

				//cout << "\n";
				temp -> next = newNode;
				
			}

			lists[mnnum] = lists[mnnum] -> next;
		}
		//cout << head -> val << " " << head -> next -> val << "\n";
		k++;
    }
    if(k == 1){
        ListNode* ans = new ListNode();
    	return nullptr;
    }
    return head;

}
};