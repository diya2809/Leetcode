class Solution {
public:
    int divide(int dividend, int divisor) {
        // Overflow case
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        // Determine the sign of the answer
        bool negative = (dividend < 0) ^ (divisor < 0);

        // Use long long to safely handle INT_MIN
        long long a = dividend;
        long long b = divisor;

        a = abs(a);
        b = abs(b);

        long long quotient = 0;

        // Subtract powers of 2 multiples of divisor
        while (a >= b) {
            long long temp = b;
            long long multiple = 1;

            while (a >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }

            a -= temp;
            quotient += multiple;
        }

        if (negative)
            quotient = -quotient;

        return (int)quotient;
    }
};