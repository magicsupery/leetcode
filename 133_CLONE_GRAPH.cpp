//
// Created by Administrator on 07/05/2020.
//
#include <vector>
#include <unordered_map>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }

    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr)
        {
            return nullptr;
        }
        Node* newNode = new Node(node->val, node->neighbors);
        map_[newNode->val] = newNode;
        cloneNeighbors(newNode);
        map_.clear();
        return newNode;
    }


    void cloneNeighbors(Node* newNode)
    {
        auto& neighbors = newNode->neighbors;
        for(size_t i = 0; i < neighbors.size(); i++)
        {
            auto neighbor = neighbors.at(i);
            if(map_.find(neighbor->val) != map_.end())
            {
                neighbors[i] = map_[neighbor->val];
            }
            else
            {
                Node* n = new Node(neighbor->val, neighbor->neighbors);
                map_[neighbor->val] = n;
                neighbors[i] = n;
                cloneNeighbors(n);
            }
        }
    }
private:
    unordered_map<int, Node*> map_;
};

int main()
{
    Node* one = new Node(1);
    Node* two = new Node(2);

    one->neighbors = vector<Node*>{two};
    two->neighbors = vector<Node*>{one};

    Solution().cloneGraph(one);
}
