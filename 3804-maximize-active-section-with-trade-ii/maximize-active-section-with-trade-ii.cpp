class SparseTable {
public:
    int n;
    vector<vector<int>> st;

    SparseTable() {}

    SparseTable(const vector<int>& a) {
        n = a.size();
        if (n == 0) return;
        int LOG = 32 - __builtin_clz(n);
        st.assign(LOG, vector<int>(n));
        st[0] = a;
        for (int k = 1; k < LOG; k++) {
            for (int i = 0; i + (1 << k) <= n; i++) {
                st[k][i] = max(st[k - 1][i],
                               st[k - 1][i + (1 << (k - 1))]);
            }
        }
    }

    int query(int l, int r) {
        if (l > r) return INT_MIN;
        int k = 31 - __builtin_clz(r - l + 1);
        return max(st[k][l], st[k][r - (1 << k) + 1]);
    }
};

class Solution {
public:
    struct Group {
        int start;
        int len;
    };

    vector<int> maxActiveSectionsAfterTrade(string s,
                                            vector<vector<int>>& queries) {
        int ones = count(s.begin(), s.end(), '1');

        vector<Group> zeroGroups;
        vector<int> zeroId(s.size());

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0') {
                if (i && s[i - 1] == '0')
                    zeroGroups.back().len++;
                else
                    zeroGroups.push_back({i, 1});
            }
            zeroId[i] = (int)zeroGroups.size() - 1;
        }

        if (zeroGroups.empty())
            return vector<int>(queries.size(), ones);

        vector<int> merge;
        for (int i = 0; i + 1 < zeroGroups.size(); i++)
            merge.push_back(zeroGroups[i].len + zeroGroups[i + 1].len);

        SparseTable st(merge);

        vector<int> ans;

        for (auto &q : queries) {
            int l = q[0], r = q[1];

            int left =
                (zeroId[l] == -1)
                    ? -1
                    : zeroGroups[zeroId[l]].len -
                          (l - zeroGroups[zeroId[l]].start);

            int right =
                (zeroId[r] == -1)
                    ? -1
                    : (r - zeroGroups[zeroId[r]].start + 1);

            int startGroup = zeroId[l] + 1;
            int endGroup =
                (s[r] == '1') ? zeroId[r] : zeroId[r] - 1;

            int best = ones;

            if (s[l] == '0' && s[r] == '0' &&
                zeroId[l] + 1 == zeroId[r]) {
                best = max(best, ones + left + right);
            } else if (startGroup <= endGroup - 1) {
                best = max(best,
                           ones +
                               st.query(startGroup, endGroup - 1));
            }

            if (s[l] == '0' &&
                zeroId[l] + 1 <= endGroup) {
                best = max(
                    best,
                    ones + left +
                        zeroGroups[zeroId[l] + 1].len);
            }

            if (s[r] == '0' &&
                zeroId[l] < zeroId[r] - 1) {
                best = max(
                    best,
                    ones + right +
                        zeroGroups[zeroId[r] - 1].len);
            }

            ans.push_back(best);
        }

        return ans;
    }
};