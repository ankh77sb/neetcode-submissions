class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        int n = position.size();
        vector<pair<int, int>> car;
        for(int i = 0; i < n; i++) {
            car.push_back({position[i], speed[i]});
        }
        sort(car.begin(), car.end(), greater<pair<int,int>>());

        int fleets = 1;
        double prevTime = (double)(target - car[0].first)/car[0].second;

        for(int i = 1; i < n; i++) {
            double currTime = (double)(target - car[i].first)/car[i].second;
            if(currTime > prevTime) {
                fleets++;
                prevTime = currTime;
            }
        }

        return fleets;

    }
};
