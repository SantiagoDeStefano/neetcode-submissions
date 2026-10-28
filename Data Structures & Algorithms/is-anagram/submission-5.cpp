class Solution {
public:
bool isAnagram(string s, string t) {
    if(s.size() != t.size()) {
        return false;
    }
    unordered_map<char, int> countMap;
    for(int i = 0; i < s.size(); i++) {
        countMap[s[i]]++;
        countMap[t[i]]--;
    }
    for(auto [key, value] : countMap) {
        if(countMap[key] != 0) {
            return false;
        }
    }
    return true;
}
};
