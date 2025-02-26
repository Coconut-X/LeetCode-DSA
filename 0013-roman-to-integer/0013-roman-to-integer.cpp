class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> mep;
        unordered_map<char, int> priority;

        mep['I']=1;     mep['V']=5; mep['X']=10;    mep['L']=50;    
        mep['C']=100;   mep['D']=500;   mep['M']=1000;
        
        int count=0;

        for(int i=0;i<s.size();i++)
        {
            if(i<s.size()-1 and mep[s[i]]<mep[s[i+1]])
            {
                count+= mep[s[i+1]] - mep[s[i]]; 
                i++;
                continue;            
            }
                count+=mep[s[i]];
           
        }

        return count;
        
    }
};