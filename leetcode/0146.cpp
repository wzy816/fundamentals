/*
146. LRU Cache

Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
Follow up:
Could you do get and put in O(1) time complexity?

*/
class Node {
public:
    int value;
    int key;
    Node* next;
    Node* pre;
};

// use doubly-linked list && map
class LRUCache {
public:
    int total;
    int size;
    map<int, Node*> m;
    Node* head;
    Node* tail;
    LRUCache(int capacity) {
        size = 0;
        total = capacity;
        head = new Node();
        tail = new Node();
        head -> next= tail;
        tail -> pre = head;
    }


    int get(int key) {
        if(m.find(key) != m.end()){
            Node* n = m[key];
            relink(n);
            placeAtHead(n);
            return n->value;
        }else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(m.find(key) != m.end()){
            Node* n = m[key];
            n->value = value;
            relink(n);
            placeAtHead(n);
        }else{
            // create new node
            Node* n = new Node();
            n->value = value;
            n->key = key;
            m[key] = n;
            
            placeAtHead(n);
            
            size = size+1;
            if(size > total){
                // find tail;
               cout << "to evict ";
                
                Node* new_tail = tail->pre->pre;
                m.erase(tail->pre->key);
                new_tail->next =tail;
                tail->pre = new_tail;
                size = size - 1;
            }
        }
        
    }
    void relink(Node* n){
        n->next->pre = n->pre;
        n->pre->next = n->next;
    }
    void placeAtHead(Node* n){
        n->next = head->next;
        head->next->pre = n;
        head->next = n;
        n->pre = head;
    }
};
