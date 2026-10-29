class Solution {
public:
int lengthOfLongestSubstring(string s) {
    int n = s.size();
    unordered_set<char> find_set;
    int left = 0;
    int right = 0;
    int maxChar = 0;
    while(right < n) {
        if(!find_set.count(s[right])) {
            find_set.insert(s[right]);
            int current = right - left + 1;
            maxChar = max(maxChar, current);
            right++;
        }
        else {
            find_set.erase(s[left]);
            left++;
        }
    }
    return maxChar;
}
};
