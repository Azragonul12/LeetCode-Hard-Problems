class Solution {
public:
    int longestValidParentheses(string s) {
	long long openedBrackets = 0 , mxSize = 0 , sz = 0;

	for(long long i = 0; s.length() > i; i++){
		if(s[i] == '('){
			openedBrackets++;
		}
		else{
			openedBrackets--;
		}

		if(openedBrackets >= 0){
			sz++;
			if(openedBrackets == 0){
				mxSize = max(mxSize , sz);
			}
		}
		else{
			openedBrackets = 0;
			mxSize = max(mxSize , sz);
			sz = 0;
		}
	}
	openedBrackets = 0;
	sz = 0;
	for(long long i = s.length() - 1; 0 <= i; i--){
		if(s[i] == ')'){
			openedBrackets++;
		}
		else{
			openedBrackets--;
		}

		if(openedBrackets >= 0){
			sz++;
			if(openedBrackets == 0){
				mxSize = max(mxSize , sz);
			}
		}
		else{
			openedBrackets = 0;
			mxSize = max(mxSize , sz);
			sz = 0;
		}
	}
	return mxSize;
}
};