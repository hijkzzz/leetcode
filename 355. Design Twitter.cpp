class Twitter {
    private:
        struct Tweet {
            int time;
            int id;
            Tweet(int time, int id) : time(time) , id(id) {}
        };

        //  hash_map 保存 Tweet 和 关注信息
        unordered_map<int, vector<Tweet>> tweets;
        // set 可以防止重复关注导致的问题
        unordered_map<int, unordered_set<int>> following;
        int time;

    public:
        /** Initialize your data structure here. */
        Twitter() : time(0){

        }

        /** Compose a new tweet. */
        void postTweet(int userId, int tweetId) {
            tweets[userId].emplace_back(time++, tweetId);
        }

        /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
        vector<int> getNewsFeed(int userId) {
            // 加载所有相关 Tweet 表
            vector<pair<vector<Tweet> *, int>> h;
            if(!tweets[userId].empty())
                h.push_back(make_pair(&tweets[userId], tweets[userId].size() - 1));
            for (auto followeeId : following[userId]) {
                if(!tweets[followeeId].empty())
                    h.push_back(make_pair(&tweets[followeeId], tweets[followeeId].size() - 1));
            }

            // 创建最大堆
            auto f = [](const pair<vector<Tweet> *, int> &a, pair<vector<Tweet> *, int> &b){ return a.first->at(a.second).time < b.first->at(b.second).time; };
            make_heap(h.begin(), h.end(), f);

            // 取出十条最近的 Tweet
            vector<int> news;
            for (int i = 0; i < 10  && !h.empty(); i++) {
                pop_heap(h.begin(), h.end(), f);
                auto &recent = h.back();

                news.push_back(recent.first->at(recent.second).id);
                --recent.second;

                if (recent.second < 0) h.pop_back();
                push_heap(h.begin(), h.end(), f);
            }
            return news;
        }

        /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
        void follow(int followerId, int followeeId) {
            if (followerId == followeeId) return;
            following[followerId].insert(followeeId);
        }

        /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
        void unfollow(int followerId, int followeeId) {
            following[followerId].erase(followeeId);
        }
};
