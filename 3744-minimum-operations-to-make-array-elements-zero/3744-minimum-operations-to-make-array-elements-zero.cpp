class Solution {
private:
    long long calculate_f(long long x) {
        if (x <= 0) {
            return 0;
        }

        long long total_ops = 0;
        int ops_per_number = 1;
        long long current_segment_start = 1;
        long long next_segment_start = 4;

        //all full segments up to x
        while (next_segment_start <= x) {

            long long num_elements = next_segment_start - current_segment_start;
            total_ops += num_elements * ops_per_number;
            current_segment_start = next_segment_start;
            next_segment_start *= 4;
            ops_per_number++;
        }

        //partial segment from current_segment_start up to x, for last numbers 
        long long num_elements_in_partial_segment = x - current_segment_start + 1;
        total_ops += num_elements_in_partial_segment * ops_per_number;
        return total_ops;
    }

public:

    long long minOperations(vector<vector<int>>& queries) {
        long long count = 0;

        for (auto q : queries) {
            long long l = q[0], r = q[1];
            long long cost = calculate_f(r) - calculate_f(l - 1);
            count += (cost + 1) / 2;
        }

        return count;
    }
};
