class Solution {
public:
void countComponents_helper(vector<int>& visited, unordered_map<int, vector<int>>& adjList, int current_node, int parent_node) {
    // Visited
    if(visited[current_node] == 1) {
        return;
    }
    visited[current_node] = 1;
    for(auto node : adjList[current_node]) {
        if(node == parent_node) {
            continue;
        }
        countComponents_helper(visited, adjList, node, current_node);
    }
}

int countComponents(int n, vector<vector<int>>& edges) {
    unordered_map<int, vector<int>> adjList;
    vector<int> visited(n, 0);
    int count = 0;
    for(auto pair : edges) {
        adjList[pair[0]].push_back(pair[1]);
        adjList[pair[1]].push_back(pair[0]);
    }

    for(int i = 0; i < n; i++) {
        if(visited[i] == 0) {
            count += 1;
        }
        countComponents_helper(visited, adjList, i, -1);
    }
    return count;
}
};
