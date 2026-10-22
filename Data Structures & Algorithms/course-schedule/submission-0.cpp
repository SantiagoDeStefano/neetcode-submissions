class Solution {
public:
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    unordered_map<int, vector<int>> adjList;
    vector<int> status(numCourses, 0);
    for(auto pair : prerequisites) {
        adjList[pair[1]].push_back(pair[0]);
    }
    for(int i = 0; i < numCourses; i++) {
        if(!canFinish_helper(status, adjList, i)) {
            return false;
        }
    }
    return true;
}

bool canFinish_helper(vector<int>& status, unordered_map<int, vector<int>>& adjList, int current_node) {
    if(status[current_node] == 2) {
        return true;
    }
    if(status[current_node] == 1) {
        return false;
    }
    status[current_node] = 1;
    for(auto nodes : adjList[current_node]) {
        if(!canFinish_helper(status, adjList, nodes)) {
            return false;
        }
    }
    status[current_node] = 2;
    return true;
}
};
