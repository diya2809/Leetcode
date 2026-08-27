class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();

        vector<int> cnt(26, 0);

        // Count characters in s
        for (char c : s) {
            cnt[c - 'a']++;
        }

        // Try to match target from left to right
        // and find the rightmost position where we can make it larger.
        for (int i = 0; i < n; i++) {
            int x = target[i] - 'a';

            // We need target[i] for the prefix.
            if (cnt[x] == 0) {
                // Cannot match this character.
                // We will handle the answer by going backwards.
                break;
            }

            cnt[x]--;
        }

        // Rebuild counts
        fill(cnt.begin(), cnt.end(), 0);
        for (char c : s) {
            cnt[c - 'a']++;
        }

        // Try changing target from right to left
        for (int i = n - 1; i >= 0; i--) {

            // Use target[0..i-1]
            bool possible = true;

            vector<int> temp = cnt;

            for (int j = 0; j < i; j++) {
                int c = target[j] - 'a';

                if (temp[c] == 0) {
                    possible = false;
                    break;
                }

                temp[c]--;
            }

            if (!possible)
                continue;

            // Find smallest character > target[i]
            int cur = target[i] - 'a';

            for (int c = cur + 1; c < 26; c++) {
                if (temp[c] > 0) {

                    string ans = target.substr(0, i);

                    ans += char('a' + c);
                    temp[c]--;

                    // Put remaining characters in sorted order
                    for (int k = 0; k < 26; k++) {
                        ans += string(temp[k], char('a' + k));
                    }

                    return ans;
                }
            }
        }

        return "";
    }
};