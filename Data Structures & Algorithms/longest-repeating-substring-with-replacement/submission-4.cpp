class Solution {
public:
    int characterReplacement(string s, int k) {
        int left_idx = 0;
        int right_idx = 0;

        int count[26] = {0};
        int maxFreq = 0;
        int maxLength = -1;

        while (right_idx < s.length()) {
            int idx = s[right_idx] - 'A';
            count[idx]++;
            maxFreq = max(maxFreq, count[idx]);

            while(right_idx - left_idx + 1 - maxFreq > k) {
                count[s[left_idx] - 'A']--;
                left_idx++;
            }
            
            maxLength = max(maxLength, right_idx - left_idx + 1);
            right_idx++;
        }
        return maxLength;
    }
};
