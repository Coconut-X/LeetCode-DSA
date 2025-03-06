class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {

        vector<int> ans(2,0);

        unordered_map<int,bool> mep;
        int s = grid.size();

        for(auto g: grid){
            for(int i=0;i<grid.size();i++)
            {
                if(mep[g[i]])
                    ans[0]=g[i];
                mep[g[i]]=true;

            }
        }

        for(int i = 1; i <= s*s ; i++){
            if(!mep[i]){
                ans[1]=i;
                break;
            }
        }

        return ans;


        
        
    }
};