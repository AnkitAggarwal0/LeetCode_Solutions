struct Node {
    int key, val; 
    Node *prev, *next; 
    Node(int k, int v): key(k), val(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private: 
    int cap; 
    std::unordered_map<int, Node*> cache;
    Node* head; Node* tail;

    void remove (Node* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void add (Node* node){
        node->next = head->next; 
        node->prev = head; 
        head->next->prev = node;
        head->next = node; 
    }

public:
    LRUCache(int capacity) : cap(capacity){
        head = new Node(-1,-1); 
        tail = new Node(-1,-1); 
        head->next = tail; 
        tail->prev = head;
    }
    
    int get(int key) {
        if (cache.find(key) == cache.end()) return -1;
        else {
            Node* mru = cache[key]; 
            remove(mru); 
            add(mru);
            return mru->val;
        }
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()){
            Node* oldNode = cache[key]; 
            remove(oldNode);
            delete oldNode;
        }

        Node* newNode = new Node(key,value); 
        cache[key] = newNode; 
        add(newNode); 

        if (cache.size() > cap){
            Node* lru = tail->prev; 
            remove(lru); 
            cache.erase(lru->key);
            delete lru;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */