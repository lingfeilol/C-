class Node
{
public:
    Node* _prev;
    Node* _next;
    int _key;
    int _value;
    Node(int key,int value)
        :_key(key)
        ,_value(value)
        ,_prev(nullptr)
        ,_next(nullptr)
    {}
};

class LRUCache {
public:
    LRUCache(int capacity) {
        _capacity=capacity;
        head=new Node(-1,-1);
        head->_prev=head->_next=head;        
    }
    //移除当前节点
    void removeNode(Node* cur)
    {
        cur->_prev->_next=cur->_next;
        cur->_next->_prev=cur->_prev;
    }
    //头插
    void frontinsert(Node* cur)
    {
        //head cur head->next
        Node* Next=head->_next;
        cur->_next=Next;
        Next->_prev=cur;
        cur->_prev=head;
        head->_next=cur; 
    }
    int get(int key) {
        if(!cachemap.count(key))
            return -1;
         // 如果 key 存在，先通过哈希表定位，再移到头部
         Node* node=cachemap[key];
         removeNode(node);//先移除
         frontinsert(node);//在插到头部，保证是最近使用过的
         return node->_value;
    }
    
    void put(int key, int value) {
        if(!cachemap.count(key))//不存在，创建一个节点，插入该组
        {
            Node* newnode=new Node(key,value);
            // 添加进哈希表
            cachemap[key]=newnode;
            frontinsert(newnode);//插到头部
            if(cachemap.size()>_capacity)//超缓存容量了
            {
                Node* tail=head->_prev;//删除尾元素
                removeNode(tail);
                cachemap.erase(tail->_key);// 删除哈希表中对应的项
            }
        }
        else//存在，找到后更新，并放到头部
        {
            Node* node=cachemap[key];
            node->_value=value;
            removeNode(node);//移除
            frontinsert(node);//头插
        }
    }
private:
    int _capacity;
    Node* head;
    unordered_map<int,Node*> cachemap;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */