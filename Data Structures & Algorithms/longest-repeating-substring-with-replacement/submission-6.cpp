class Solution {
public:
int characterReplacement(string s, int k) {
    int n = s.size();
    int left = 0;
    int maxFreq = 0;
    int maxLength = 0;
    unordered_map<char, int> countMap;

    for(int right = 0; right < n; right++) {
        countMap[s[right]]++;

        maxFreq = max(maxFreq, countMap[s[right]]);

        while( (right - left + 1) - maxFreq > k) {
            countMap[s[left]]--;
            left++;
        }

        maxLength = max(maxLength, right - left + 1);
    }

    return maxLength;
}

};
