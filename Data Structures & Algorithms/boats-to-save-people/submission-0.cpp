class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {

        int n = people.size();
        sort(people.begin(), people.end());
        int res = 0;
        int i = 0, j = n - 1;

        for(; i < j; res++) {
            if(people[i] + people[j] <= limit) {
                i++;
                j--;
            } else {
                j--;
            }
        }

        return res + (i==j);
        
    }
};