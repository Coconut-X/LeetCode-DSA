class Solution {
public:

    bool isPrefixAndSuffix(string str1, string str2)
    {
        if(str1.size() > str2.size())
            return false;
                
        int s1=str1.size(), s2=str2.size();
        for(int i=0, j=0; i<str2.size() and j<s1;i++)
        {
            if(str2[i]!=str1[j] or str1[s1-1-j]!=str2[s2-1-i])
                return false;
            j++;
        }

        return true;
    }

    int countPrefixSuffixPairs(vector<string>& words) {
        
        int count=0;
        for(int i=0;i<words.size()-1;i++)
            for(int j=i+1;j<words.size();j++)
                if( isPrefixAndSuffix(words[i],words[j]))
                    count++;

        return count;
    }
};