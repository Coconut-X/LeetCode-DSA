class Solution {
public:

    inline int perimeter(int a, int b, int c){
        if(a+b <= c or a+c <= b or b+c <= a){
            return 0;
        }
        return a+b+c;
    }

    int largestPerimeter(vector<int>& nums) {

        int s = nums.size();
        sort(nums.begin(), nums.end());

        for(int i = s-1; i >=2; i--){
            int p = perimeter(nums[i], nums[i-1], nums[i-2]);
            if(p){
                return p;
            }
        }
        return 0;
    }
};