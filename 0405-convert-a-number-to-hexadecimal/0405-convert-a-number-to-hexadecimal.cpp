class Solution {
public:
    string toHex(long num) {
        
        if(num==0) return "0";
       
        if(num<0)
            num += 4294967296;

        auto alphabet=[](const int num){
            return num + 'a' - 10;
        };

        string hex="";
        while(num)
        {
            int rem=num%16;
            if(rem>=10) hex+=alphabet(rem);
            else hex+=to_string(rem);
            num/=16;
        }

        reverse(hex.begin(), hex.end());
        return hex;
    }
};