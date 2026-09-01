class TimeMap {
    unordered_map<string, vector<pair<int, string>>> mp;

public:
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {

        auto it = mp.find(key);

        if (it == mp.end())
            return "";

        const vector<pair<int, string>>& space = it->second;

        int start = 0;
        int end = space.size() - 1;
        int res = -1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (space[mid].first == timestamp)
                return space[mid].second;

            if (space[mid].first <= timestamp) {
                res = mid;
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }

        return res == -1 ? "" : space[res].second;
    }
};