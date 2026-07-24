class Solution {
public:
    int minOperations(string s, int k) {
        int n = s.size();
        int zero = 0;

        for (char c : s)
            if (c == '0') zero++;

        for (int t = 0; t <= n; t++) {
            long long total = 1LL * t * k;

            if (total < zero) continue;
            if ((total - zero) & 1) continue;

            long long needExtra = (total - zero) / 2;

            long long capacity =
                1LL * zero * ((t - 1) / 2) +
                1LL * (n - zero) * (t / 2);

            if (needExtra <= capacity)
                return t;
        }

        return -1;
    }
};