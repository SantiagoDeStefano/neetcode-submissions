class Solution {
public:
bool validTree_helper(unordered_map<int, vector<int>>& adjList, vector<int>& status, int current_node, int parent_node) {
    // Visited
    if(status[current_node] == 2) {
        return true;
    }
    // Visiting
    if(status[current_node] == 1) {
        return false;
    }
    // Set to visiting
    status[current_node] = 1;
    for(auto node : adjList[current_node]) {
        if(node == parent_node) {
            continue;
        }
        if(!validTree_helper(adjList, status, node, current_node)) {
            return false;
        }
    }
    // Set to visited
    status[current_node] = 2;
    return true;
}


bool validTree(int n, vector<vector<int>>& edges) {
    unordered_map<int, vector<int>> adjList;
    vector<int> status(n, 0);
    for(auto pairs : edges) {
        adjList[pairs[0]].push_back(pairs[1]);
        adjList[pairs[1]].push_back(pairs[0]);
    }
    if(!validTree_helper(adjList, status, 0, -1)) {
        return false;
    }
    for(int i = 0; i < n; i++) {
        if(status[i] != 2) {
            return false;
        }
    }
    return true;
}

};
