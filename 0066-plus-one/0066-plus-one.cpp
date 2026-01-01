class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carryout = 1;
        for(int i = digits.size() - 1; i >= 0; i--){
            if(carryout == 0) break;
            int n = digits[i];
            digits[i] = (digits[i] + carryout)%10;
            carryout = digits[i] ==0;
        }
        if(carryout == 1){
            digits.insert(digits.begin(),1);
        }
        return digits;
    }
};