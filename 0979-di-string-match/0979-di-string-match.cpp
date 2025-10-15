class Solution {
public:
    vector<int> diStringMatch(string s) {
        int I = 0, D = s.size();
        vector<int> ans;
        for(int i = 0; i < s.size(); i++){
            if(s[i]=='I')   ans.push_back(I++);
            if(s[i]=='D')   ans.push_back(D--);
        }
        if(D>=0) ans.push_back(D);
        else  ans.push_back(I);
        
        return ans;
    }
};