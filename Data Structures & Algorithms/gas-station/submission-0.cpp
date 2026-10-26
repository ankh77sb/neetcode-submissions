class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        int n = gas.size();
        int tgas = 0;
        int tcost = 0;
        for(int g: gas) {
            tgas += g;
        }
        for(int c: cost) {
            tcost += c;
        }

        if(tgas < tcost) return -1;
        int c = 0;
        int idx = 0;
        for(int i = 0 ; i < n; i++) {
            c += gas[i] - cost[i];
            if(c < 0){ c = 0; idx = i + 1;}
        }
        return idx;
    }
};
