class Solution {
public:
vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> result(2);
    unordered_map<int, int> index_map;
    for(int i = 0; i < nums.size(); i++) {
        index_map[nums[i]] = i;
    }
    for(int i = 0; i < nums.size(); i++) {
        int number = target - nums[i];
        if(index_map[number] && index_map[number] != i) {
            result[0] = (index_map[number]);
            result[1] = (i);
            sort(result.begin(), result.end());
            return result;
        }
    }
    return result;
}
};
