class Solution {
public:
    int bs(vector<int>&p, long long success, int s){
        int l = 0, h = p.size()-1;

        while(l<=h){
            int mid = l + (h-l)/2;
            if((long long)s*p[mid]<success){
                l = mid+1;
            }
            else{
                h = mid -1;
            }
        }
        return l;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        int s = 0;
        vector<int>ans;
        for(int i = 0; i < spells.size(); i++){
            int index = bs(potions,success,spells[i]); 
            ans.push_back(potions.size() - bs(potions,success,spells[i]));
        }
        return ans;

    }
};