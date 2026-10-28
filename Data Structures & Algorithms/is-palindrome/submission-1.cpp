class Solution {
public:
bool isPalindrome(string s) {
    string cleaned = "";
    for(auto x : s) {
        if(isalnum(x)) {
            cleaned += tolower(x);
        }
    }
    int left = 0;
    int right = cleaned.size() - 1;

    while(left <= right) {
        if(cleaned[left] != cleaned[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}
};
