class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        
        for(int i=1;i<=k;i++)
        {
            auto it=max_element(gifts.begin(),gifts.end());
            int m=*max_element(gifts.begin(),gifts.end());
            *it=sqrt(m);
        }

        long long int s=0;
        for(int i=0;i<gifts.size();i++)
            s+=gifts[i];
        return s;

    }
};