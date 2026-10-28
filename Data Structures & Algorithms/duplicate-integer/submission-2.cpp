class Solution {
public:
bool hasDuplicate(vector<int>& nums) {
    unordered_map<int, int> countMap;
    for(auto num : nums) {
        countMap[num]++;
    }    
    for(auto num : nums) {
        if(countMap[num] >= 2) {
            return true;
        }
    }
    return false;
}
};