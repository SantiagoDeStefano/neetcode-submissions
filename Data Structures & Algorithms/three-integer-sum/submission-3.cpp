class Solution {
public:
vector<vector<int>> threeSum(vector<int>& nums) {
    int n = nums.size();
    set<vector<int>> ans;
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());
    for(int i = 0; i < n; i++) {
        int left = i + 1;
        int right = n - 1;
        while(left < right) {
            if(nums[i] + nums[left] + nums[right] < 0) {
                left++;
            }
            else if(nums[i] + nums[left] + nums[right] > 0) {
                right--;
            }
            else {
                ans.insert({nums[i], nums[left], nums[right]});
                left++;
            }
        }
    }
    for(auto x : ans) {
        result.push_back(x);
    }
    return result;
}
};
