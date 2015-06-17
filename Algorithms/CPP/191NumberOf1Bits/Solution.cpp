class Solution {
public:
    int hammingWeight(uint32_t n) {
        uint32_t s = 0x0001;
        int counter = 0;
        for(int i = 1; i <= 32; i++) {
            if((n & s) != 0) {
                counter++;
            }
            s = s<<1;
        }
        return counter;
    }
};