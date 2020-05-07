//
// Created by Administrator on 06/05/2020.
//
#include <vector>
#include <unordered_map>
#include <stdlib.h>
using namespace std;
class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet():
    map_(1000)
    {
        vector_.reserve(1000);
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(map_.find(val) != map_.end())
        {
            return false;
        }

        vector_.emplace_back(val);
        map_[val] = vector_.size() - 1;
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(map_.find(val) == map_.end())
        {
            return false;
        }

        auto index = map_[val];
        auto lastVal = vector_.back();
        map_[lastVal] = index;
        vector_[index] = lastVal;

        vector_.pop_back();
        map_.erase(val);
        return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
        return vector_[rand() % vector_.size()];
    }
private:
    unordered_map<int, int> map_;
    vector<int> vector_;

};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

#include <iostream>
int main()
{
    // 初始化一个空的集合。
    RandomizedSet randomSet;

// 向集合中插入 1 。返回 true 表示 1 被成功地插入。
    std::cout << randomSet.insert(1) << std::endl;

// 返回 false ，表示集合中不存在 2 。

    std::cout << randomSet.remove(2) << std::endl;

// 向集合中插入 2 。返回 true 。集合现在包含 [1,2] 。
    std::cout << randomSet.insert(2) << std::endl;

// getRandom 应随机返回 1 或 2 。
    std::cout << randomSet.getRandom() << std::endl;

// 从集合中移除 1 ，返回 true 。集合现在包含 [2] 。
    std::cout << randomSet.remove(1) << std::endl;

// 2 已在集合中，所以返回 false 。
    std::cout << randomSet.insert(2) << std::endl;

// 由于 2 是集合中唯一的数字，getRandom 总是返回 2 。
    std::cout << randomSet.getRandom() << std::endl;
}