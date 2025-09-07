class Solution {
public:
    
    int log4(double number){
        int result = (int)((log(number) / log(4.0)) + 1);
        return result;
    }

    long long minOperations(vector<vector<int>>& queries) {
        long long count = 0;

        for(auto q:queries){
            int l = q[0], r = q[1];
            long long cost = 0;
            for(int i = l;i<=r;){
                long long minop = log4(i); //current min op
                int boundary = pow(4,minop) -1;

                long long last_num = min(boundary, r);
                long long elements_in_this_segment = last_num - i + 1;

                cost+=minop*elements_in_this_segment;
                
                i=last_num+1; //move to next segment
            }

            count+=(cost+1)/2;
        }
        
        return count;
    }
};