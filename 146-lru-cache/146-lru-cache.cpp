class LRUCache {
public:
    class node{
    public: 
        int key;
        int value;
        node* next;
        node* prev;

        node(int _key,int _value){
            key=_key;
            value = _value;
        }
    };
    
    node* head= new node(-1,-1);
    node* tail = new node(-1,-1);
    
    int cap;
    unordered_map<int,node*>m;
    
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev= head;
    }
    void addNode(node* newnode){
        node* temp = head->next;
        newnode->next=temp;
        newnode->prev= head;
        head->next = newnode;
        temp->prev = newnode;
    }
    void deleteNode(node* delnode){
        node* delprev = delnode->prev;
        node* delnext = delnode->next;
        delprev -> next = delnext;
        delnext ->prev = delprev;
    } 
    int get(int key) {
        if(m.find(key)!=m.end()){
            node* resNode =m[key];
            int res= resNode->value;
            m.erase(key);
            deleteNode(resNode);
            addNode(resNode);
            m[key]=head->next;
            return res;
        }
        return -1;
    }
    void put(int key, int value) {
        if(m.find(key)!=m.end()){
            node* existingNode = m[key];
            m.erase(key);
            deleteNode(existingNode);
        }
        if(m.size()==cap){
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new node(key,value));
        m[key]=head->next;
    }
};

