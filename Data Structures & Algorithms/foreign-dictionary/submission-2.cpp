class Solution {
public:
bool foreignDictionary_helper(unordered_map<char, vector<char>>& adjList, vector<char>& result, char current_char, vector<char>& visited) {
    // visited
    if(visited[current_char - 'a'] == '2') {
        return true;
    }
    // visiting
    if(visited[current_char - 'a'] == '1') {
        return false;
    }
    visited[current_char - 'a'] = '1';
    for(auto x : adjList[current_char]) {
        if(!foreignDictionary_helper(adjList, result, x, visited)) {
            return false;
        }
    }
    visited[current_char - 'a'] = '2';
    result.push_back(current_char);
    return true;
}

string foreignDictionary(vector<string>& words) {
    unordered_map<char, vector<char>> adjList;
    vector<char> result;
    string final;
    vector<char> visited(26, 0);

    for(auto word : words) {
        for(char ch : word) {
            adjList[ch];
        }
    }

    for(int i = 0; i < words.size() - 1; i++) {
        int size = min(words[i].size(), words[i + 1].size());
        
        if(
            words[i].substr(0, size) == words[i + 1].substr(0, size)
            &&
            words[i].size() > words[i + 1].size()
        ) {
            return "";
        }

        for(int j = 0; j < size; j++) {
            if(words[i][j] != words[i + 1][j]) {
                adjList[words[i][j]].push_back(words[i + 1][j]);
                break;
            }
        }
    }

    for(auto [key, value] : adjList) {
        if(!foreignDictionary_helper(adjList, result, key, visited)) {
            return "";
        }
    }

    for(int i = result.size() - 1; i >= 0; i--) {
        final += result[i];
    }
    return final;
}
};
