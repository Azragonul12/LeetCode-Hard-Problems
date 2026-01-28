class Solution {
public:
bool ans = false;
string st , pt;
bool isMatching(char a , char b){
	if(b == '.'){
		return true;
	}
	if(b == a){
		return true;
	}
	return false;
}
void solve(long long num , long long mum){

	//cout << num << " " << mum << "\n";
	if(num >= st.length()){
		if(num == st.length() && mum == (pt.length())){
			ans = true;
		}
		else{
			mum--;
			while(num == st.length() && (mum + 2) < pt.length() && pt[mum + 2] == '*'){
				mum += 2;
			}
			if(num == st.length() && mum == (pt.length() - 1)){
				ans = true;
			}
		}
		return;
	}
	if(mum >= pt.length()){
		return;
	}

	if(pt[mum] == '*'){
		if(isMatching(st[num] , pt[mum - 1])){
			solve(num + 1 , mum);
			solve(num + 1 , mum + 1);
		}
		
	}
	else{
		if(isMatching(st[num] , pt[mum])){
			solve(num + 1 , mum + 1);
		}
		if(mum < pt.length() && pt[mum + 1] == '*'){
			solve(num , mum + 1);
			solve(num , mum + 2);
		}
	}
	
}
bool isMatch(string s, string p) {
    st = s;
    pt = p;
    string newP = "";
    for(long long i = 0; p.length() > i; i++){
    	newP = newP + p[i];
    	if((i + 2) < p.length() && p[i] == '*' && p[i + 2] == '*' && p[i - 1] == p[i + 1]){
    		i += 2;
    	}
    }
    pt = newP;
	   solve(0 , 0);
	   return ans;     
}
};