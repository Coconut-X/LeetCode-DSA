class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int left = 0, right = colors.size() - 1;
        int m = 0;
        while(left<right){
            if(colors[left]!=colors[right]){
                m = right - left;
                break;
            }
            right --;
        }

        left = 0, right = colors.size() - 1;
       
        while(left<right){
            if(colors[left]!=colors[right]){
                m = max(m,right - left);
                break;
            }
            left++;
        }
        return m;
    }
};