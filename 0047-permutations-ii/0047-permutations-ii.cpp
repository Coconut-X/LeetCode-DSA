#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    void brute(vector<int>& nums, vector<bool>& used, vector<vector<int>>& perms, vector<int>& perm) {
        if (perm.size() == nums.size()) {
            perms.push_back(perm);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue;
        
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) {
                continue; 
            }

            used[i] = true;
            perm.push_back(nums[i]);

            brute(nums, used, perms, perm);

            used[i] = false;
            perm.pop_back();
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> perms;
        vector<int> perm;
        vector<bool> used(nums.size(), false);

        sort(nums.begin(), nums.end());
        brute(nums, used, perms, perm);

        return perms;
    }
};

