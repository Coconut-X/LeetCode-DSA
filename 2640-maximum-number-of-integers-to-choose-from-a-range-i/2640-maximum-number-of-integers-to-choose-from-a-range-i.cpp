class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
    unordered_map<int,int> m; //to do all searches in O(1)
    for(int i=0;i<banned.size();i++)
    {
        m[banned[i]]++;
    }

    unordered_map<int,bool>chosen;

    int count=0;
    int sum=0;
   
    for(int i=1;i<=n;i++)
    {
        if(sum+i>maxSum) break;

        if(!chosen[i]and !m[i])
        {
            count++;
            sum+=i;
        }
    }

    return count;


    }
};