class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int count = 0;
        int n = colors.size();
        int dist=1;
        for(int i=0;i<=n+k-3;i++){
            if(colors[i%n]!=colors[(i+1)%n]){
                dist++;
            }
            else dist=1;
            if(dist>=k) count++;
        }

        return count;
    }
};
