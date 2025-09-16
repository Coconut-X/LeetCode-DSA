class Solution {
public:

    int gcd(int a, int b){
        if(b==0) return a;
        return gcd(b, a%b);
    }

    vector<int> replaceNonCoprimes(vector<int>& nums) {
        int i = 1;
        stack<int> s;
        s.push(nums[0]);
        while(i<nums.size()){
            int cur = nums[i];
            while(!s.empty()){
                int t = s.top();
                int g = gcd(max(t,cur), min(t,cur));
                if(g>1){
                    s.pop();
                    long long l = t*(cur/g);
                    cur = (int)l;
                }
                else{
                    break;
                }
            }
            s.push(cur);
            i++;
        }

        vector<int> ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};