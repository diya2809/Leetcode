class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        const int MAXX = 2048;

        vector<vector<bool>> dp(4, vector<bool>(MAXX, false));
        dp[0][0] = true;

        for (int x : nums) {
            for (int k = 3; k >= 1; --k) {
                for (int xr = 0; xr < MAXX; ++xr) {
                    if (dp[k - 1][xr]) {
                        dp[k][xr ^ x] = true;
                    }
                }
            }
        }

        vector<bool> seen(MAXX, false);

        // Triplets with repeated indices produce the element itself.
        for (int x : nums) {
            seen[x] = true;
        }

        // Triplets with three distinct indices.
        for (int xr = 0; xr < MAXX; ++xr) {
            if (dp[3][xr]) {
                seen[xr] = true;
            }
        }

        int ans = 0;
        for (bool v : seen) {
            if (v) ++ans;
        }

        return ans;
    }
};
