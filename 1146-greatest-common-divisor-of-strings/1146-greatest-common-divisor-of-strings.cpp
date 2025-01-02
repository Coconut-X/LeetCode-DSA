class Solution {
public:

    int euclid(int l1, int l2)
    {
        if(l1==0) return l2;
        return euclid(l2%l1,l1);
    }

    string gcdOfStrings(string str1, string str2) {

        if(str1+str2 != str2+str1) return "";
        
        string gcd(str1, 0, euclid( max(str1.size(),str2.size()), min(str1.size(),str2.size()) ));

        return gcd;
       
    }
};