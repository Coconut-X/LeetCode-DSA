class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {

        unordered_map<int,int> freq;
        unordered_map<int,bool> unique;

        for(int i=0;i<arr.size();i++)
        {
            freq[arr[i]]++;
        }

        for(auto& [key,count] : freq)
        {
            if(unique[count]) return false;
            unique[count]=true;
        }

        return true;
        
    }
};