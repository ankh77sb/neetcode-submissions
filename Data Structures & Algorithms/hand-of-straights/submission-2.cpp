class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        vector<int> frq(1001, 0);
        int n = hand.size();
        for(int i = 0; i < n; i++) {
            frq[hand[i]]++;
        }

        sort(hand.begin(), hand.end());

        for(int i = 0; i < n; i++) {
            int j = hand[i];
            int cSize = 0;
            while(cSize < groupSize && frq[j]) {
                cSize++;
                frq[j]--;
                j++;
            }
            if(cSize != groupSize) {
                j = hand[i];
                int k = 0;
                while(k < cSize) {
                    k++;
                    frq[j]++;
                    j++;
                }
            }
        }

        for(int i = 0; i < n; i++) {
            if(frq[hand[i]]) return false;
        }

        return true;

    }
};
