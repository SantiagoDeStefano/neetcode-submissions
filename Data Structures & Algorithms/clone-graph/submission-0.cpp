/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr) {
            return nullptr;
        }

        unordered_map<Node*, bool> visited;
        unordered_map<Node*, vector<Node*>> adjList;
        unordered_map<Node*, Node*> cloneMap;

        adjList_helper(node, visited, adjList);

        for(auto& [key, value] : adjList) {
            cloneMap[key] = new Node(key->val); 
        }

        for(auto& [key, value] : adjList) {
            for(auto nb : value) {
                cloneMap[key]->neighbors.push_back(cloneMap[nb]);
            }
        }
        return cloneMap[node];
    }

    void adjList_helper(
        Node* node, 
        unordered_map<Node*, bool>& visited, 
        unordered_map<Node*, vector<Node*>>& adjList
    ) {
        if (node == nullptr || visited[node] == true) {
            return;
        }
        
        for(auto nodes : node->neighbors) {
            adjList[node].push_back(nodes);
        }
        
        visited[node] = true;
        adjList[node];

        for(auto nodes : node->neighbors) {
            adjList_helper(nodes, visited, adjList);
        }
    }
};
