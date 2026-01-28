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
   ListNode* reverseKGroup(ListNode* head, int k) {
	vector < ListNode* > reversing;
	ListNode* eh = head;
	ListNode* last;
	while(eh != nullptr){
		ListNode* temp = eh;
		ListNode* nxt = eh -> next;
		reversing.push_back(temp);

		if(reversing.size() == k){
			if(last != nullptr){
				//cout << last -> val << " ";
				last -> next = reversing[k - 1];
				if(reversing[k - 1] == head){
					last = head;
				}
			}
			for(long long i = k - 1; 0 < i; i--){
				reversing[i] -> next = reversing[i - 1];
				
			}
			if(eh -> next != nullptr){
				reversing[0] -> next = nxt;
				
			}
			last = reversing[0];

			if(reversing[0] == head){
				head = reversing[k - 1];
			}
			reversing.clear();
		}
		eh = nxt;
		//cout << eh -> val << " ";
	}
	return head;
}
};