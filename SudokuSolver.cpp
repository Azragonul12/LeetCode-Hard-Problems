class Solution {
public:
    bool check(long long val , long long x , long long y , vector<vector<char> >& board){
	for(long long i = 0; 9 > i; i++){
		if(board[x][i] - '0' == val || board[i][y] - '0' == val){
			return false;
		}
	}

	long long xi = (x / 3) * 3;
	long long yi = (y / 3) * 3;
	for(long long i = 0; 3 > i; i++){
		for(long long j = 0; 3 > j; j++){
			if(board[i + xi][j + yi] - '0' == val){
				return false;
			}
		}
	}
	return true;

}

vector < pair <long long , long long> > available;
vector<vector<char> > really;
vector<vector<char> > ehe;
bool going(long long num){
	bool flag = false;
	if(num >= available.size()){
		really = ehe;
		return true;
	}
	for(long long i = 1; 9 >= i; i++){
		if(check(i , available[num].first , available[num].second , ehe)){
			ehe[available[num].first][available[num].second] = (i + '0');
			if(going(num + 1) == true){
				flag = true;
				return flag;
			}
            ehe[available[num].first][available[num].second] = '.';
		}
	}
	return flag;
}
void solveSudoku(vector<vector<char> >& board){
	for(long long i = 0; board.size() > i; i++){
		for(long long j = 0; board[i].size() > j; j++){
			if(board[i][j] == '.'){
				available.push_back(make_pair(i , j));
			}
		}
	}
    ehe = board;
	going(0);
	board = really;
        
}
};