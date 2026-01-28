class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        long long n = nums1.size();
        long long m = nums2.size();

        long long l1 = 0 , l2 = 0;

        double median = 0;
        vector <long long> res;
        while(n > l1 && m > l2 && (n + m) / 2 >= (l1 + l2)){
            if(nums1[l1] > nums2[l2]){
                res.push_back(nums2[l2]);
                l2++;
            }
            else{
                res.push_back(nums1[l1]);
                l1++;
            }
        }
        while(n > l1 && (n + m) / 2 >= (l1 + l2)){
            res.push_back(nums1[l1]);
            l1++;
            
        }
         while(m > l2 && (n + m) / 2 >= (l1 + l2)){
            res.push_back(nums2[l2]);
            l2++;
            
        }

        if((n + m) % 2 == 1){
            return res[(n + m) / 2];
        }
        else{
            median = res[(n + m) / 2];
            median += (res[((n + m) / 2) - 1]);

            median /= 2;
            return median;
        }
    }
};