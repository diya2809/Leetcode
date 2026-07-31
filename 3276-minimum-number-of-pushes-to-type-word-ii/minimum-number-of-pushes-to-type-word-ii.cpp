class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26, 0);
        
        // Count frequencies
        for (char c : word) {
            freq[c - 'a']++;
        }
        
        // Sort in descending order
        sort(freq.begin(), freq.end(), greater<int>());
        
        int pushes = 0;
        
        // Assign costs
        for (int i = 0; i < 26; i++) {
            if (freq[i] == 0) break;
            
            int cost = (i / 8) + 1; // group of 8
            pushes += freq[i] * cost;
        }
        
        return pushes;
    }
};