class Twitter {
    unordered_map<int, vector<pair<int, int>>> postMap; 
    unordered_map<int, unordered_set<int>> followList;
    int t;
public:
    Twitter() {
        t = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        postMap[userId].push_back({t++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> pq;
        vector<int> res;
        for(auto p: postMap[userId]) {
            pq.push(p);
        }

        for(int followeeId: followList[userId]) {
            for(auto p: postMap[followeeId]) {
                pq.push(p);
            }
        }

        int count = 0;
        while(!pq.empty() && count<10) {
            res.push_back(pq.top().second);
            pq.pop();
            count++;
        }

        return res;

    }
    
    void follow(int followerId, int followeeId) {
        if(followerId != followeeId)
        followList[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followList[followerId].erase(followeeId);
    }
};
