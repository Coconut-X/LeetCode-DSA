class Solution {
public:

    vector<int> constructLps(string pat){
        vector<int> lps(pat.size(),0);
        int len =0;
        int i=1;
        while(i<pat.size()){
            if(pat[i]==pat[len]){
                len++;
                lps[i]=len;
                i++;
            }

            else{
                if(len==0){
                    lps[i]=0;
                    i++;
                }
                else{
                   
                    len = lps[len-1];
                }
            }
        }

        return lps;
    }

    int strStr(string haystack, string needle) {

        vector<int> lps;
        lps = constructLps(needle);

        int i=0, j=0;
        int n = haystack.size(), m = needle.size();
        while(i<n){
            if(haystack[i] == needle[j]){
                i++, j++;
                if(j==m){
                    return i-j;
                    //j=lps[j-1];
                }
            }
            else{
                if(j==0){
                    i++;
                }
                else{
                    j = lps[j-1];
                }
            }
        }
        return -1;
    }
};