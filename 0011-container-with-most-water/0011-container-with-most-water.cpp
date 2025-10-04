class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i = 0, j = n - 1;
        int m = INT_MIN;
        do{
            m = max(m, min(height[i],height[j])*abs(i-j));
            if(height[i] < height[j]){
                i++;
            }
            else{
                j--;
            }


        }while(i < j);

        return m;
    }
};