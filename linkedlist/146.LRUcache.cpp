// Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

// Implement the LRUCache class:

// LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
// int get(int key) Return the value of the key if the key exists, otherwise return -1.
// void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
// The functions get and put must each run in O(1) average time complexity.

// Example 1:

// Input
// ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
// [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
// Output
// [null, null, null, 1, null, -1, null, -1, 3, 4]

#include <bits/stdc++.h>
#include "/leetcode/precompiled/ListNode.h"
using namespace std;

class Node {
    public:
    int k;
    int val;
    Node* prev;
    Node* next;

    Node(int key, int value) {
        k = key;
        val = value;
        prev = NULL;
        next = NULL;
    }
};

class LRUCache {
    public:
        LRUCache(int capacity) {
            cap = capacity;

            left = new Node(0, 0);
            right = new Node(0, 0);

            left->next = right;
            right->prev = left;
        }

        int get(int key) {
            if(cache.find(key) != cache.end()) {
                remove(cache[key]);
                insert(cache[key]);
                return cache[key]->val;
            }
            return -1;
        }

        void put(int key, int value) {
            if (cache.find(key) != cache.end()) {
                remove(cache[key]);

                delete cache[key];
            }

                cache[key] = new Node(key, value);
                insert(cache[key]);

                if(cache.size() > cap) {
                    Node* lru = left->next;
                    remove(lru);
                    cache.erase(lru->k);

                delete lru;
                }
        }

        private:
            int cap;
            unordered_map<int, Node*> cache;
            Node* left;
            Node* right;

        void remove(Node* node) {
            Node* prev = node->prev;
            Node* next = node->next;

            prev->next = next;
            next->prev = prev;
        }

        void insert(Node* node) {
            Node* prev = right->prev;
            Node* next = right;

            prev->next = node;
            next->prev = node;

            node->prev = prev;
            node->next = next;
        }
};


