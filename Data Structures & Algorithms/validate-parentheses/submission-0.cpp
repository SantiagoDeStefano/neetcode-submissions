class Solution {
public:
    bool isValid(string s) {
        stack<char> checkStack;

        for (char x : s) {

            if (x == '(' || x == '{' || x == '[') {
                checkStack.push(x);
            }
            else {
                if (checkStack.empty()) return false;

                if (x == ')' && checkStack.top() != '(') return false;
                if (x == '}' && checkStack.top() != '{') return false;
                if (x == ']' && checkStack.top() != '[') return false;

                checkStack.pop();
            }
        }

        return checkStack.empty();
    }
};