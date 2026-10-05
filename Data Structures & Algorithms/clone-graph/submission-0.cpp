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
    Node* dfs(unordered_map<Node*,Node*>& nodeMap, Node* node) {
        if(node == nullptr) return nullptr;
        if(nodeMap.find(node) == nodeMap.end()) {
            nodeMap[node] = new Node(node->val);
        } else return nodeMap[node];
        for(int i = 0; i < node->neighbors.size(); i++)
            nodeMap[node]->neighbors.push_back(dfs(nodeMap, node->neighbors[i]));
        return nodeMap[node];
    }
    
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> oldToNew;
        return dfs(oldToNew, node);
    }
};
