class Solution {
public:
    string minWindow(string s, string t) {
        int need[128] = {0};
        for (char c : t) need[c]++;

        int required = 0;
        for (int i = 0; i < 128; i++) if (need[i] > 0) required++;

        int count[128] = {0};
        int matched = 0;
        int left_idx = 0, minLength = INT_MAX, start = 0;

        for (int right_idx = 0; right_idx < (int)s.length(); right_idx++) {
            char c = s[right_idx];
            count[c]++;
            if (need[c] > 0 && count[c] == need[c]) matched++;

            while (matched == required) {
                if (right_idx - left_idx + 1 < minLength) {
                    minLength = right_idx - left_idx + 1;
                    start = left_idx;
                }
                char lc = s[left_idx];
                if (need[lc] > 0 && count[lc] == need[lc]) matched--;
                count[lc]--;
                left_idx++;
            }
        }
        return minLength == INT_MAX ? "" : s.substr(start, minLength);
    }
};