struct CacheNode{
    int key;
    int value;
    CacheNode* prev;
    CacheNode* next;

    CacheNode(int k, int v) : key(k), value(v), prev(NULL), next(NULL) {}
};

class LRUCache{
    public:
        LRUCache(int _capacity) :
            capacity(_capacity), head(new CacheNode(-1, -1)), tail(head), length(0) {
            }

        int get(int key) {
            if(m_map.find(key) != m_map.end()){
                CacheNode *node = m_map[key];
                //移动到链表头
                deleteNode(node);
                insertToHead(node);
                return node->value;
            }
            else
                return -1;
        }

        void set(int key, int value) {
            if(m_map.find(key) != m_map.end()){
                CacheNode *node = m_map[key];
                //移动到链表头
                deleteNode(node);
                node->value = value;
                insertToHead(node);
            }
            else{
                if(length == capacity){
                    //删除链表尾
                    m_map.erase(tail->key);
                    CacheNode *node = tail;
                    deleteNode(tail);
                    delete node;
                }
                insertToHead(new CacheNode(key, value));
                m_map[key] = head->next;
            }
        }

    private:
        int capacity;
        unordered_map<int, CacheNode *> m_map;

        //双向循环链表
        CacheNode *head;
        CacheNode *tail;
        int length;

        void insertToHead(CacheNode *node){
            //空链表
            if(head == tail){
                head->next = node;
                head->prev = node;
                node->next = head;
                node->prev = head;
                tail = node;
            }
            else{
                node->next = head->next;
                node->prev = head;
                head->next->prev = node;
                head->next = node;
            }
            length++;
        }

        void deleteNode(CacheNode *node){
            //删除链表尾
            if(node == tail){
                tail = node->prev;
                tail->next = head;
                head->prev = tail;
            }
            else{
                CacheNode *prev = node->prev, *next = node->next;
                prev->next = next;
                next->prev = prev;
            }
            length--;
        }
};
