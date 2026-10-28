class Solution {
public:

string encode(vector<string>& strs) {
    string encoded;
    for(int i = 0; i < strs.size(); i++) {
        encoded += to_string(strs[i].size()) + '#' + strs[i];
    }
    return encoded;
}

vector<string> decode(string s) {
    vector<string> result;
    for(int i = 0; i < s.size();) {
        for(int j = i; j < s.size(); j++) {
            if(s[j] == '#') {
                int length = stoi(s.substr(i, j));
                result.push_back(s.substr(j + 1, length));
                i = j + 1 + length;
                break;
            }
        }
    }
    return result;
}
};
