class Solution {
public:
    void combinationSum_helper(
        vector<int>& nums, 
        int index, 
        int sum, 
        int target, 
        vector<int>& comb, 
        vector<vector<int>>& results) {
        if (sum == target) {
            results.push_back(comb);
            return;
        }
        if(sum > target || index >= nums.size()) {
            return;
        }
        
        comb.push_back(nums[index]);
        combinationSum_helper(nums, index, sum + nums[index], target, comb, results);

        comb.pop_back();
        combinationSum_helper(nums, index + 1, sum, target, comb, results);

    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> comb;
        vector<vector<int>> results;
        combinationSum_helper(nums, 0, 0, target, comb, results);
        return results;
    }
};
