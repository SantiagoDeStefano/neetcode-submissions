class Solution {
public:
vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> countMap;
    for(auto num : nums) {
        countMap[num]++;
    }
    vector<pair<int, int>> v(countMap.begin(), countMap.end());
    sort(v.begin(), v.end(), [](auto& a , auto& b) {
        return a.second > b.second;
    });
    vector<int> result;
    for (int i = 0; i < k; i++) {
        result.push_back(v[i].first);
    }
    return result;
}

};
