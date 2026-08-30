class Solution {
public:
    vector<vector<int>> ans;
    vector<int> current;

    void backtrack(vector<int>& candidates, int target, int index) {
        // Target reached
        if (target == 0) {
            ans.push_back(current);
            return;
        }

        // Try each candidate
        for (int i = index; i < candidates.size(); i++) {

            // Candidate is too large
            if (candidates[i] > target)
                break;

            // Choose
            current.push_back(candidates[i]);

            // Same i -> can use the same number again
            backtrack(candidates, target - candidates[i], i);

            // Undo choice
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        backtrack(candidates, target, 0);

        return ans;
    }
};