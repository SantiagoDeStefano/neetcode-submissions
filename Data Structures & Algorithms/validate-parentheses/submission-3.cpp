class Solution {
public:
bool isValid(string s) {
    stack<int> checkStack;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == ')' || s[i] == ']' || s[i] == '}') {
            if(checkStack.empty()) {
                return false;
            }
            char top_char = checkStack.top();
            if(
                s[i] == ')' && top_char != '(' ||
                s[i] == ']' && top_char != '[' ||
                s[i] == '}' && top_char != '{'
            ) {
                return false;
            }
            checkStack.pop();
        }
        else {
            checkStack.push(s[i]);
        }
    }
    return checkStack.empty();
}
};
