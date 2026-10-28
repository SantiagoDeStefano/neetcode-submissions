class Solution {
public:
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> group;
    vector<vector<string>> result;
    vector<string> components;
    for(int i = 0; i < strs.size(); i++) {
        string current_string = strs[i];
        sort(current_string.begin(), current_string.end());
        group[current_string].push_back(strs[i]);
    }
    for(auto [key, value] : group) {
        result.push_back(group[key]);
    }
    return result;
}
};
