class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector <int> ans;
        map <string , int> mp;

        for(long long i = 0; words.size() > i ;i++){
        	mp[words[i]]++;
        }
        for(long long j = 0; words[0].length() > j; j++){
        	map <string , int> mp1;
        	long long dis = 0;
        	long long h = (s.length() - (words.size() * words[0].length()));
        	for(long long i = j; h >= i; i += words[0].length()){
        		cout << h << " ";
        		
        		if(i == j){
        			for(long long k = 0; words.size() > k; k++){
        				long long beg = i + k * words[0].length();
		        		long long end = i + (k + 1) * words[0].length();
		        		string wrd = "";
		        		for(int y = beg; end > y; y++){
		        			wrd = wrd + s[y];
		        		}
        				mp1[wrd]++;
        				if(mp1[wrd] == mp[wrd]){
        					dis += mp[wrd];
        				}

        			}
        		}
        		else{
        			long long beg = i + (words.size() - 1) * words[0].length();
	        		long long end = i + (words.size()) * words[0].length();
	        		string wrd = "";
	        		for(int y = beg; end > y; y++){
	        			wrd = wrd + s[y];
	        		}
        			mp1[wrd]++;
        			if(mp1[wrd] == mp[wrd]){
        				dis += mp[wrd];
        			}

        		}
        		if(dis == words.size()){
        			ans.push_back(i);
        		}
        		long long beg = i;
        		long long end = i + words[0].length();
        		string wrd = "";
        		for(int y = beg; end > y; y++){
        			wrd = wrd + s[y];
        		}
        		if(mp1[wrd] == mp[wrd]){
        			dis -= mp[wrd];
        		}
        		mp1[wrd]--;
        		
        		//cout << dis << " ";
        		
        	}
        }
        return ans;
}
};