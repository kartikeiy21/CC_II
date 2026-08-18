class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int a,b,c;
        int maxi = nums[0];
        int mini = nums[0];
        int ans = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            a = nums[i] * maxi;
            b = nums[i] * mini;
            c = nums[i];
            maxi =max(a,max(b,c));
            mini= min (a,min(b,c));
            ans = max(ans, maxi);
        }

        return ans;
    }
};