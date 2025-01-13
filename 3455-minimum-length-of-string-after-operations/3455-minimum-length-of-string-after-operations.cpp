class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char, int> freq;
        vector<char> unique;

        for(auto c: s)
        {
            if(!freq[c]) unique.push_back(c);
            freq[c]++;
        }

        int total=s.size();

        for(auto c: unique)
        {
            int x=freq[c];
            if(x%2==0 and x!=2)
            {
                total=total - x + 2;
            }
            else if(x%2==1 and x!=1)
            {
                total=total - x + 1;
            }

        }

        return total;
    }
};