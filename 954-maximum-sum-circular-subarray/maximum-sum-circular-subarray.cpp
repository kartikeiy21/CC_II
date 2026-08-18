class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
      int a,b,c,d;
        int maxi = nums[0];
        int mini = nums[0];
        int ans = nums[0];
        int sum = nums[0];
        int min_ans = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            a = nums[i] ;
            b = nums[i] + maxi;
            maxi=max(a,b);
            c = nums[i] + mini ;
            mini= min (a,c);
            ans = max(ans, maxi);
            min_ans= min(min_ans,mini);
            sum += nums[i];
            
        }
        if (ans<0)
               return ans;

        return max(ans,sum-min_ans);  
    }
};