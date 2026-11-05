class Solution {
public:
bool valid(unordered_map<char, int>& countMap_s, unordered_map<char, int>& countMap_t) {
    for(auto [key, value_t] : countMap_t) {
        if (countMap_s[key] < value_t) {
            return false;
        }
    }
    return true;
}

string minWindow(string s, string t) {
    unordered_map<char, int> countMap_s;
    unordered_map<char, int> countMap_t;
    int minArea = INT_MAX;
    int start = 0;
    int left = 0;
    int right = 0;

    for(int i = 0; i < t.size(); i++) {
        countMap_t[t[i]]++;
    }

    while(right < s.size()) {
        countMap_s[s[right]]++;
        while(valid(countMap_s, countMap_t)) {
            if(right - left + 1 < minArea) {
                minArea = right - left + 1;
                start = left;
            }
            countMap_s[s[left]]--;
            left++;
        }
        right++;
    }
    
    string result = "";
    if(minArea == INT_MAX) {
        return result;
    }
    return s.substr(start, minArea);
}

};
