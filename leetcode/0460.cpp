/*
460. LFU Cache

Design and implement a data structure for a Least Frequently Used (LFU) cache.

Implement the LFUCache class:

LFUCache(int capacity) Initializes the object with the capacity of the data structure.
int get(int key) Gets the value of the key if the key exists in the cache. Otherwise, returns -1.
void put(int key, int value) Update the value of the key if present, or inserts the key if not already present. When the cache reaches its capacity, it should invalidate and remove the least frequently used key before inserting a new item. For this problem, when there is a tie (i.e., two or more keys with the same frequency), the least recently used key would be invalidated.
To determine the least frequently used key, a use counter is maintained for each key in the cache. The key with the smallest use counter is the least frequently used key.

When a key is first inserted into the cache, its use counter is set to 1 (due to the put operation). The use counter for a key in the cache is incremented either a get or put operation is called on it.

*/

// refer to http://dhruvbird.com/lfu.pdf
// Using one link list as frequency list, one link list for each FreqNode, and a map to store key-node relation.

class FreqNode;

class Node {
public:
    int key;
    int value;
    FreqNode* freqNode;
    Node* parent;
    Node* child;
    
};

class FreqNode {
 public:
    FreqNode* prev;
    FreqNode* next;
    Node* nhead;
    Node* ntail;
    int freq;
    
};

class LFUCache {
public:
    map<int, Node*> m;
    int size;
    FreqNode* head;
    FreqNode* tail;
    LFUCache(int capacity) {
        head = new FreqNode();
        tail = new FreqNode();
        head->next = tail;
        tail->prev = head;
        size = capacity;
    }
    
    int get(int key) {
        if(m.find(key) == m.end()){
            return -1;
        }
        
        Node* n = m[key];
        FreqNode* fn = n->freqNode;
        FreqNode* fn2;
        if(fn->next->freq == fn->freq+1){
            fn2 = fn->next;
        }else{
            fn2 = createFreqNode(fn->freq+1, fn, fn->next);
        }
        
        deleteNode(n);
        insertNode(n, fn2, fn2->nhead, fn2->nhead->child);

        if(fn->nhead->child == fn->ntail){
            deleteFreqNode(fn);
        }      
        return n-> value;        
    }
    
    FreqNode* createFreqNode(int freq, FreqNode* prev, FreqNode* next){
        FreqNode* n = new FreqNode();
        n->freq = freq;
        n->next = next;
        next->prev = n;
        n->prev = prev;
        prev->next = n;
        n->nhead = new Node();
        n->ntail = new Node();
        n->nhead->child = n->ntail;
        n->ntail->parent = n->nhead;
        return n;
    }
    void insertNode(Node* n, FreqNode* fn, Node* parent, Node* child){
        parent->child = n;
        n->parent = parent;
        n->child =  child;
        child->parent = n;
        n->freqNode = fn;
        return;
    }
    
    void deleteFreqNode(FreqNode* n){
        n->prev->next = n->next;
        n->next->prev = n->prev;
        return;
    }
    void deleteNode(Node* n){
        n->parent->child = n->child;
        n->child->parent = n->parent;
        return;
    }
    
    void put(int key, int value) {
        if(size == 0){
            return;
        }
        if(m.find(key) != m.end()){
            Node* n = m[key];
            n->value = value;
            get(key);
            return;
        }
        if(m.size() == size){
            Node* toEvict = head->next->ntail->parent;
            deleteNode(toEvict);
            m.erase(toEvict->key);
        }
        Node* n = new Node();
        n->key=key;
        n->value = value;
        m[key] = n;
        if(head->next->freq != 1){
            createFreqNode(1, head, head->next);
        }
        insertNode(n, head->next, head->next->nhead, head->next->nhead->child);
        
        return;
    }
};
