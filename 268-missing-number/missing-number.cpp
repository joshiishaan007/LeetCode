class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xor1 = 0, xor2 = 0;
        int N = nums.size();
        for (int i = 0; i < N; i++) {
            xor2 = xor2 ^ nums[i]; // XOR of array elements
            xor1 = xor1 ^ i; //XOR up to [1...N-1]
        }
        xor1 = xor1 ^ N; //XOR up to [1...N]

        return (xor1 ^ xor2 ^ 0); // the missing number
    }
};