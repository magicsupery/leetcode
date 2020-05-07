//
// Created by Administrator on 06/05/2020.
//

#include <unordered_map>
#include <list>
using namespace std;
class LRUCache {
public:
    LRUCache(int capacity):
        capacity_(capacity)
    {

    }

    int get(int key) {
        if(map_.find(key) == map_.end())
        {
            return -1;
        }

        auto it = map_[key];

        auto nodePointer = *it;
        list_.erase(it);
        list_.push_front(nodePointer);
        map_[key] = list_.begin();
        return nodePointer->value;
    }

    void put(int key, int value) {
        if(capacity_ <= 0)
        {
            return;
        }

        if(map_.find(key) == map_.end())
        {
            if(list_.size() >= capacity_)
            {
                auto it = --list_.end();
                auto nodePointer = *it;
                map_.erase(map_.find(nodePointer->key));
                list_.pop_back();

                delete nodePointer;
            }
            list_.push_front(new ListNode(key, value));
            map_[key] = list_.begin();
        }
        else{
            auto it = map_[key];
            auto nodePointer = *it;
            nodePointer->value = value;
            list_.erase(it);
            list_.push_front(nodePointer);
            map_[key] = list_.begin();
        }
    }

private:
    struct ListNode{
        int key;
        int value;
        ListNode(int k, int v):
                key(k),
                value(v)
        {

        }
    };
    list<ListNode*> list_;
    using MyIterator = list<ListNode*>::iterator;
    unordered_map<int, MyIterator> map_;
    int capacity_;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

#include <iostream>
int main()
{
    LRUCache cache(2);

    cache.put(2, 1);
    cache.put(2, 2);
    std::cout << cache.get(2) << std::endl;
    cache.put(1, 1);
    cache.put(4, 1);
    std::cout << cache.get(2) << std::endl;
}