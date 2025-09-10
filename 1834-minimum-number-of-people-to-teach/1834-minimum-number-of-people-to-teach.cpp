class Solution {
public:

    bool knows(vector<vector<int>>& languages, int user, int lan) {
        for (int i = 0; i < languages[user].size(); i++) {
            if (languages[user][i] == lan)
                return true;
        }
        return false;
    }

    bool hasCommon(vector<vector<int>>& languages, int f1, int f2) {
        for (int i = 0; i < languages[f1].size(); i++) {
            for (int j = 0; j < languages[f2].size(); j++) {
                if (languages[f1][i] == languages[f2][j]) return true;
            }
        }
        return false;
    }

    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m = INT_MAX;

        vector<vector<int>> badFriendships;
        for (int i = 0; i < friendships.size(); i++) {
            int f1 = friendships[i][0] - 1, f2 = friendships[i][1] - 1;
            if (!hasCommon(languages, f1, f2)) {
                badFriendships.push_back({f1, f2});
            }
        }

        if (badFriendships.empty()) return 0;

        for (int lan = 1; lan <= n; lan++) {
            vector<bool> taught(languages.size(), false);
            int count = 0;

            for (int i = 0; i < badFriendships.size(); i++) {
                int f1 = badFriendships[i][0], f2 = badFriendships[i][1];

                if (!knows(languages, f1, lan) && !taught[f1]) {
                    taught[f1] = true;
                    count++;
                }
                if (!knows(languages, f2, lan) && !taught[f2]) {
                    taught[f2] = true;
                    count++;
                }
            }
            m = min(m, count);
        }

        return m;
    }
};
