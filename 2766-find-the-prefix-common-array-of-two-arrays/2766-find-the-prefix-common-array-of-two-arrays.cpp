class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> ans;
        unordered_set<int> seenA, seenB;
        int commonCount = 0;

        for (int i = 0; i < A.size(); i++) {
            seenA.insert(A[i]);
            seenB.insert(B[i]);

            if (seenA.find(B[i]) != seenA.end()) commonCount++;
            if (seenB.find(A[i]) != seenB.end() && A[i] != B[i]) commonCount++;  

            ans.push_back(commonCount);
        }

        return ans;
    }
};
