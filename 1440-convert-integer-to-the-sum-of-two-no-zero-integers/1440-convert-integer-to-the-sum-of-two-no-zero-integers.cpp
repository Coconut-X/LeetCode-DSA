class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        string y = "", z = "";
        int borrow = 0;
        while(n){
            int curDigit = n%10;
            n/=10;
            curDigit-=borrow;
            borrow = 0;
            
            if(curDigit<0){
                curDigit = 9;
                borrow = 1;
            }

            if(curDigit==0 and n==0) break;

            if(curDigit==1){
                //cout<<"h";
                if (n == 0){
                    z += "1";
                   // cout<<"a";
                    break;
                }
                borrow = 1;
                y+="2";
                z+="9";
               // cout<<y<<" "<<z<<endl;
            }
            if(curDigit !=1){
                if(curDigit==0){
                    z+="9";
                    borrow = 1;
                }
                else
                    z+= curDigit - 1 +'0';
                y+="1";
                //cout<<y<<" "<<z<<endl;

            }

        }

        reverse(y.begin(),y.end());
        reverse(z.begin(),z.end());

        return {stoi(y),stoi(z)};
    }
};