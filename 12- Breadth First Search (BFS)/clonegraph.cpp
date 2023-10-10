#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include<set>
#include<bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) {
            return nullptr;
        }
        
        unordered_map<Node*, Node*> nodeMap; // Original node to cloned node mapping
        queue<Node*> q; // Queue for BFS
        
        // Create the first cloned node and add it to the queue
        Node* clonedNode = new Node(node->val);
        nodeMap[node] = clonedNode;
        q.push(node);
        
        while (!q.empty()) {
            Node* currentNode = q.front();
            q.pop();
            
            // Iterate through the neighbors of the current node
            for (Node* neighbor : currentNode->neighbors) {
                // If the neighbor hasn't been cloned yet, create a clone
                if (nodeMap.find(neighbor) == nodeMap.end()) {
                    Node* clonedNeighbor = new Node(neighbor->val);
                    nodeMap[neighbor] = clonedNeighbor;
                    q.push(neighbor);
                }
                
                // Connect the cloned nodes
                nodeMap[currentNode]->neighbors.push_back(nodeMap[neighbor]);
            }
        }
        
        return nodeMap[node]; // Return the cloned node corresponding to the input node
    }
};

// Helper function to print the graph
void printGraph(Node* node, unordered_set<Node*>& visited) {
    if (!node || visited.count(node)) {
        return;
    }
    visited.insert(node);
    cout << "Node " << node->val << " neighbors: ";
    for (Node* neighbor : node->neighbors) {
        cout << neighbor->val << " ";
    }
    cout << endl;
    for (Node* neighbor : node->neighbors) {
        printGraph(neighbor, visited);
    }
}

int main() {
    // Create a sample graph
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);

    node1->neighbors = {node2, node4};
    node2->neighbors = {node1, node3};
    node3->neighbors = {node2, node4};
    node4->neighbors = {node1, node3};

    Solution solution;
    Node* clonedGraph = solution.cloneGraph(node1);

    // Print the original and cloned graphs
    unordered_set<Node*> visited;
    cout << "Original Graph:" << endl;
    printGraph(node1, visited);
    
    visited.clear();
    cout << "\nCloned Graph:" << endl;
    printGraph(clonedGraph, visited);

    return 0;
}
