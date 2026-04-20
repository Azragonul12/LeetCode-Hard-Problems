class Solution {
public:
   int firstMissingPositive(vector<int>& nums) {
	for(long long i = 0; nums.size()  > i; i++){
		long long piv = i;
		long long f = 0;
		while(nums[piv] != piv + 1 && nums[piv] > 0 && nums[piv] <= nums.size()){
			long long lp = piv;
			piv = nums[piv] - 1;
			if(f)
				nums[lp] = lp + 1;

			f = 1;
		}
		//cout << piv << " ";
		if(i != piv){
			nums[piv] = piv + 1;
		} 
	}
	for(long long i = 0; nums.size() > i; i++){
		//cout << nums[i] << " ";
		if(nums[i] != i + 1){
			return i + 1;
		}
	}        
	return nums.size() + 1;
}
};