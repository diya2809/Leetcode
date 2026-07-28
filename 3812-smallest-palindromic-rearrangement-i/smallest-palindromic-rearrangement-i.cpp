class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> freq(26, 0);

        for (char c : s)
            freq[c - 'a']++;

        string first = "";
        string middle = "";

        for (int i = 0; i < 26; i++) {
            first.append(freq[i] / 2, char('a' + i));
            if (freq[i] % 2)
                middle = char('a' + i);
        }

        string second = first;
        reverse(second.begin(), second.end());

        return first + middle + second;
    }
};