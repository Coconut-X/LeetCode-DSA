class Solution {
public:
    unordered_map<int,int>mp;
    int brute(vector<int>& arr,vector<vector<int>>&mep, int i, int j) {
       if(mep[i][j]!=-1) return mep[i][j];
       int nextvalue = arr[i]+arr[j];
       if(!mp.count(nextvalue)) return mep[i][j] = 0;
       int k = mp[nextvalue]; //index of next value;
       return mep[i][j] = 1 + brute(arr,mep,j,k);
    }

    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size(), m = 2;
        vector<vector<int>> dp(arr.size(), vector<int>(arr.size(),-1));
        for(int i = 0; i < arr.size(); i++){
            mp[arr[i]] = i;
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                m = max(m, brute(arr, dp, i, j) + 2);
            }
        }
        return m < 3 ? 0 : m;
    }   
};
