#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <chrono>

using namespace std;
class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter() {

    }

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        if(id2Post_.find(userId) == id2Post_.end())
        {
            list<Post> v;
            id2Post_[userId] = v;
        }

        auto now = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        id2Post_[userId].emplace_front(Post(tweetId, now));
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        auto followees = id2Followee_[userId];
        std::vector<BucketIterator> v;
        std::vector<BucketIterator> endv;
        for(auto& followee: followees)
        {
            if(id2Post_.find(followee) != id2Post_.end())
            {
                auto vec = id2Post_[followee];
                if(vec.begin() != vec.end())
                {
                    v.emplace_back(vec.begin());
                    endv.emplace_back(vec.end());
                }
            }
        }

        auto vec = id2Post_[userId];
        if(vec.begin() != vec.end())
        {
            v.emplace_back(vec.begin());
            endv.emplace_back(vec.end());
        }

        vector<int> res;

        while((v.size() > 0) && (res.size() < 10) )
        {
            int maxTime = 0;
            int last = -1;
            for(size_t i = 0; i < v.size(); ++i)
            {
                auto it = v[i];
                if((*it).time > maxTime)
                {
                    maxTime = (*it).time;
                    last = i;
                }
            }

            if(last != -1)
            {
                auto it = v[last];
                res.emplace_back(it->id);
                if(++it == endv[last])
                {
                    swap(v[last], v[v.size() - 1]);
                    v.pop_back();

                    swap(endv[last], endv[endv.size() - 1]);
                    endv.pop_back();
                }
            }
        }

        return res;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if(id2Followee_.find(followerId) == id2Followee_.end())
        {
            unordered_set<int> s;
            id2Followee_[followerId] = s;
        }

        id2Followee_[followerId].insert(followeeId);
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if(id2Followee_.find(followerId) == id2Followee_.end())
        {
            return;
        }

        id2Followee_[followerId].erase(followeeId);
    }
private:
    struct Post
    {
        int id;
        uint64_t time;
        Post(int i, int t): id(i), time(t){}
    };

    unordered_map<int, unordered_set<int>> id2Followee_;
    unordered_map<int, list<Post>> id2Post_;
    using BucketIterator = list<Post>::iterator;

};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */

#include <iostream>
int main()
{
    Twitter twitter;

    twitter.postTweet(1, 5);

    twitter.getNewsFeed(1);

    twitter.follow(1, 2);

    twitter.postTweet(2, 6);

    twitter.getNewsFeed(1);

    twitter.unfollow(1, 2);

    twitter.getNewsFeed(1);
}