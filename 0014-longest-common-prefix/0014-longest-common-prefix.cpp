class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        string lcp = "";
        int minLen = INT_MAX;

        for(string s: strs){
            minLen = min(minLen,(int)s.size());
        }


        for(int j = 0; j<minLen;j++){
            
            char c = strs[0][j];
            // cout<<c<<endl;
            bool match = true;
            for(int i =1 ;i<strs.size();i++){
                cout<<c<<" "<<strs[i][j]<<endl;
                if(c!=strs[i][j]){
                    match = false;
                    break;
                }
            }
            if(match){
                lcp+=c;
            }
            else{
                break;
            }
        }
        
        return lcp;
    }
};