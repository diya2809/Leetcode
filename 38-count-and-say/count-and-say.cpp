class Solution {
public:
    string countAndSay(int n) {
        string result = "1";

        for (int i = 1; i < n; i++) {
            string next = "";

            int j = 0;

            while (j < result.size()) {
                int count = 0;
                char digit = result[j];

                // Count consecutive same digits
                while (j < result.size() && result[j] == digit) {
                    count++;
                    j++;
                }

                // Add count followed by digit
                next += to_string(count);
                next += digit;
            }

            result = next;
        }

        return result;
    }
};