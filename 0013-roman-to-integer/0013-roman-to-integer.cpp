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
            if(i<s.size()-1)
            {
                if (s[i] == 'I' && s[i + 1] == 'V') {
                    count += 4, i++;
                    continue;
                }

                if (s[i] == 'I' && s[i + 1] == 'X') {
                    count += 9 , i++;
                    continue;
                }

                if (s[i] == 'X' && s[i + 1] == 'L') {
                    count += 40, i++;
                    continue;
                }

                if (s[i] == 'X' && s[i + 1] == 'C') {
                    count += 90, i++;
                    continue;
                }

                if (s[i] == 'C' && s[i + 1] == 'D') {
                    count += 400,i++;
                    continue;
                }

                if (s[i] == 'C' && s[i + 1] == 'M') {
                    count += 900, i++;
                    continue;
                }
                            
            }

            if(i<s.size())
                count+=mep[s[i]];
            
        }

        return count;
        
    }
};