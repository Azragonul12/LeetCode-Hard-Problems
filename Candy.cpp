class Solution {
public:
    static const int nMax = 2e4 + 7;
long long vis[nMax];
long long dep[nMax];
vector <long long> adj[nMax];

void dfs(long long num){
	//cout << dep[num] << "\n";
	long long y = 0;
	vis[num] = 1;
	for(int i = 0; adj[num].size() > i; i++){
		if(vis[adj[num][i]] == 0){
			dfs(adj[num][i]);
		}
		y = max(y , dep[adj[num][i]]);
	}
	dep[num] = y + 1;
}
int candy(vector<int>& ratings){
	for(long long i = 0; ratings.size() > i; i++){
		if(i > 0 && ratings[i] > ratings[i - 1]){
			adj[i].push_back(i - 1);
		}
		if((i + 1) < ratings.size() && ratings[i] > ratings[i + 1]){
			adj[i].push_back(i + 1);
		}
	}
	for(long long i = 0; ratings.size() > i; i++){
		if(vis[i] == 0){
			dfs(i);
		}
	}
	long long ans = 0;
	for(long long i = 0; ratings.size() > i; i++){
		ans += dep[i];
	}
	return ans;
}
};