class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        string t = "1" + s + "1";
        int totalOnes = 0;

        for (char c : s)
            totalOnes += (c == '1');

        vector<pair<char, int>> blocks;

        int n = t.size();
        for (int i = 0; i < n;) {
            int j = i;
            while (j < n && t[j] == t[i]) j++;
            blocks.push_back({t[i], j - i});
            i = j;
        }

        int ans = totalOnes;

        for (int i = 1; i + 1 < blocks.size(); i++) {
            if (blocks[i].first == '1' &&
                blocks[i - 1].first == '0' &&
                blocks[i + 1].first == '0') {

                int gain = blocks[i - 1].second + blocks[i + 1].second;
                ans = max(ans, totalOnes + gain);
            }
        }

        return ans;
    }
};
