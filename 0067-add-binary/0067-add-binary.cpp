class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        int i = a.size() - 1;
        int j = b.size() - 1;
        string s = "";
        while(i >= 0 and j >= 0){
            int sum = a[i] - '0' + b[j] - '0' + carry;
            if(sum == 2){
                s+='0';
                carry = 1;
            }
            if(sum == 3){
                s+="1";
                carry = 1;
            }
           
            if(sum == 1){
                s+='1';
                carry = 0;
            }
            if(sum == 0){
                s+='0';
            }
            i--; j--;
        }
        cout << s<<endl;
        while(i>=0){
            int sum = a[i] - '0' + carry;
            if(sum == 2){
                s+='0';
                carry = 1;
            }
            if(sum == 1){
                s+='1';
                carry = 0;
            }
            if(sum == 0){
                s+='0';
            }
            i--;
        }
        cout << s<<endl;

        while(j>=0){
            int sum = b[j] - '0' + carry;
            if(sum == 2){
                s+='0';
                carry = 1;
            }
            if(sum == 1){
                s+='1';
                carry = 0;
            }
            if(sum == 0){
                s+='0';
            }
            j--;
        }
        cout << s<<endl;

        if(carry == 1) s+='1';
        cout << s<<endl;

        reverse(s.begin(), s.end());
        cout << s<<endl;

        return s;
    }
};