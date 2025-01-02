class Solution {
public:

    bool helper(string curr, int i)
    {
        return curr[i]=='a' or curr[i]=='e' or curr[i]=='i' or curr[i]=='o' or curr[i]=='u';
    }


    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {

        unordered_map<int,int> m;
        
        int count=0;

        for(int i=0;i<words.size();i++)
        {
            string curr=words[i];
            int n=curr.size();
            if(helper(curr,0) and helper(curr,n-1))
            {
                count++;
            }
            m[i]=count;
        }

        vector<int> ans;
        for(int i=0; i<queries.size();i++)
        {
            int s=queries[i][0];
            int e=queries[i][1];

            int sum=m[e]-m[s-1];
           
            ans.push_back(sum);
        }

        return ans;
        
    }
};