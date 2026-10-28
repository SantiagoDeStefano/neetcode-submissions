class Solution {
public:
int longestConsecutive(vector<int>& nums) {
    int n = nums.size();
    int maxCount = 0;
    int count = 1;
    unordered_set<int> find_set;
    for(int i = 0; i < n; i++) {
        find_set.insert(nums[i]);
    }

    for(int x : find_set) {
        if(find_set.count(x - 1)) {
            continue;
        }
        while(find_set.count(x + count)) {
            count = count + 1;
        }
        maxCount = max(maxCount, count);
        count = 0;
    }
    return maxCount;
}
};
