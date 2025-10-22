
class Solution {
public:
     long long maxFrequency(vector<int>& A, long long k, long long numOperations) {
        sort(A.begin(), A.end());

        // Case 1
        unordered_map<int, long long> count;
        long long res = 0, i = 0, j = 0, n = A.size();
        for (int a : A) {
            while (j < n && A[j] <= a + k) {
                count[A[j]]++;
                j++;
            }
            while (i < n && A[i] < a - k) {
                count[A[i]]--;
                i++;
            }
            long long cur = min(j - i, count[a] + numOperations);
            res = max(res, cur);
        }

        // Case 2

        for (long long i = 0, j = 0; j < n; j++) {
            while (A[i] + k + k < A[j]) {
                i++;
            }
            res = max(res, min(j - i + 1, numOperations));
        }
        return res;
    }
};