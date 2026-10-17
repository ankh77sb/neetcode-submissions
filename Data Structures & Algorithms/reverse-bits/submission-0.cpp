class Solution {
public:
    uint32_t reverseBits(uint32_t n) {

        for(int i = 0; i < 16; i++) {
            int f = (n >> (31 - i)) & 1U;
            int b = (n >> i) & 1U;

            if(f != b) {
                n ^= (1U << (31 - i));
                n ^= (1U << i);
            }
        }

        return n;
    }
};