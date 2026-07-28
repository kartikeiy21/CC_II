class Solution {
public:
    void solve(vector<int>& candidates, int target, int idx,
               vector<int>& temp, vector<vector<int>>& ans) {
        
        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        if (idx == candidates.size() || target < 0)
            return;

        // Take the current element (can be taken multiple times)
        temp.push_back(candidates[idx]);
        solve(candidates, target - candidates[idx], idx, temp, ans);
        temp.pop_back();

        // Skip the current element
        solve(candidates, target, idx + 1, temp, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;

        solve(candidates, target, 0, temp, ans);

        return ans;
    }
};