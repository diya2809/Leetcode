class Solution {
public:
    vector<string> ans;

    vector<string> mp = {
        "", "", "abc", "def", "ghi",
        "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    void solve(string &digits, int idx, string curr) {

        if (idx == digits.size()) {
            ans.push_back(curr);
            return;
        }

        string letters = mp[digits[idx] - '0'];

        for (char ch : letters) {
            solve(digits, idx + 1, curr + ch);
        }
    }

    vector<string> letterCombinations(string digits) {

        if (digits.empty())
            return {};

        solve(digits, 0, "");

        return ans;
    }
};