/*
460. LFU Cache
Diffuculty - Hard

Design and implement a data structure for a Least Frequently Used (LFU) cache.

Implement the LFUCache class:

    LFUCache(int capacity) Initializes the object with the capacity of the data structure.
    int get(int key) Gets the value of the key if the key exists in the cache. Otherwise, returns -1.
    void put(int key, int value) Update the value of the key if present, or inserts the key if not already present. When the cache reaches its capacity, it should invalidate and remove the least frequently used key before inserting a new item. For this problem, when there is a tie (i.e., two or more keys with the same frequency), the least recently used key would be invalidated.

To determine the least frequently used key, a use counter is maintained for each key in the cache. The key with the smallest use counter is the least frequently used key.

When a key is first inserted into the cache, its use counter is set to 1 (due to the put operation). The use counter for a key in the cache is incremented either a get or put operation is called on it.

The functions get and put must each run in O(1) average time complexity.

 

Example 1:

Input
["LFUCache", "put", "put", "get", "put", "get", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [3], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, 3, null, -1, 3, 4]

Explanation
// cnt(x) = the use counter for key x
// cache=[] will show the last used order for tiebreakers (leftmost element is  most recent)
LFUCache lfu = new LFUCache(2);
lfu.put(1, 1);   // cache=[1,_], cnt(1)=1
lfu.put(2, 2);   // cache=[2,1], cnt(2)=1, cnt(1)=1
lfu.get(1);      // return 1
                 // cache=[1,2], cnt(2)=1, cnt(1)=2
lfu.put(3, 3);   // 2 is the LFU key because cnt(2)=1 is the smallest, invalidate 2.
                 // cache=[3,1], cnt(3)=1, cnt(1)=2
lfu.get(2);      // return -1 (not found)
lfu.get(3);      // return 3
                 // cache=[3,1], cnt(3)=2, cnt(1)=2
lfu.put(4, 4);   // Both 1 and 3 have the same cnt, but 1 is LRU, invalidate 1.
                 // cache=[4,3], cnt(4)=1, cnt(3)=2
lfu.get(1);      // return -1 (not found)
lfu.get(3);      // return 3
                 // cache=[3,4], cnt(4)=1, cnt(3)=3
lfu.get(4);      // return 4
                 // cache=[4,3], cnt(4)=2, cnt(3)=3

 

Constraints:

    1 <= capacity <= 104
    0 <= key <= 105
    0 <= value <= 109
    At most 2 * 105 calls will be made to get and put.

*/

#include<bits/stdc++.h>

using namespace std;

class LFUCache {
    // This node structure is the basic cache unit
    struct node {
        int key, value, freq;
        node *left, *right;
        node(int k, int v) {
            key=k;
            value=v;
            freq=1;
            left=right=NULL;
        }
    };

    // This map stores the list of nodes for a particular frequency
    // list is defined by start and end nodes with end node being least recently used
    // Rest oif the nodes are in between
    map<int, pair<node*,node*> > freqMap;

    // This map stores the key node pair to get node for particular key
    map<int,node*> nodeMap;

    int cap;    // Capacity
    int size;   // Current Size of Cache
    int lowestFreq; // Stores lowest frequency of all nodes in cache

    // Remove specified node from frequency Map list and node map
    void removeNode(node *n) {
        nodeMap.erase(n->key);
        int f = n->freq;
        node *st = freqMap[f].first;
        node *en = freqMap[f].second;
        if(n == st) {
            st = st->right;
            if(st) st->left = NULL;
            else {
                if(f == lowestFreq) lowestFreq = INT_MAX;
                freqMap.erase(f);
                return;
            }
        }
        else if(n == en) {
            en = en->left;
            en->right = NULL;
        }
        else {
            n->left->right = n->right;
            n->right->left = n->left;
        }
        n->left = n->right = NULL;
        freqMap[f] = {st, en};
        return;
    }

    // Add Node to frequency map list and node map
    void addNode(node *n) {
        int f = n->freq;
        if(f < lowestFreq) lowestFreq = f;
        if(freqMap.find(f) == freqMap.end()) {
            freqMap[f] = {n, n};
        }
        else {
            node *st = freqMap[f].first;
            node *en = freqMap[f].second;
            n->right = st;
            st->left = n;
            st = n;
            freqMap[f] = {st, en};
        }
        nodeMap[n->key] = n;
        return;
    }

    // Delete Least Frequently Used node
    void deleteLFUNode() {
        node *n = freqMap[lowestFreq].second;
        removeNode(n);
        size--;
        delete(n);
    }
public:
    LFUCache(int capacity) {
        cap = capacity;
        size = 0;
        lowestFreq = INT_MAX;
    }
    
    int get(int key) {
        if(nodeMap.find(key) == nodeMap.end()) return -1;
        node *n = nodeMap[key];
        removeNode(n);
        n->freq = n->freq+1;
        addNode(n);
        return n->value;
    }
    
    void put(int key, int value) {
        node *n;
        if(nodeMap.find(key) == nodeMap.end()) {
            if(size == cap) deleteLFUNode();
            n = new node(key, value);
            size++;
            addNode(n);
        }
        else {
            n = nodeMap[key];
            removeNode(n);
            n->freq = n->freq+1;
            n->value = value;
            addNode(n);
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

// Driver Function
int main() {
	int cap;
	cout<<"Enter Capacity: ";
	cin>>cap;
	LFUCache lfu = LFUCache(cap);
	cout<<"Perform Operation:\n";
	while(true) {
		cout<<"Enter Choice:\n1. Get\t2. Put\t3. Exit\n";
		int ch,k,v;
		cin>>ch;
		switch(ch) {
		case 1:
			cout<<"Key: ";
			cin>>k;
			cout<<"Value Returned: "<<lfu.get(k)<<"\n";
			break;
		case 2:
			cout<<"Key: ";
			cin>>k;
			cout<<"Value: ";
			cin>>v;
			lfu.put(k,v);
			cout<<"Added\n";
			break;
		case 3:
			exit(0);
		default:
			cout<<"Please Enter Correct Choice!\n";
		}
	}
	return 0;
}

/*
How to Run Program

1. Use command to compile code: "g++ 460-lfu-cache.cpp -o lfu"
2. Run file lfu: "./lfu"
*/