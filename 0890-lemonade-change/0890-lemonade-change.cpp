class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int>cash(3,0);
        
        for(int i = 0; i < bills.size(); i++){
            int b = bills[i];
            if(b==5){
                cash[0]++;
            }
            if(b==10){
                if(cash[0]==0) return false; 
                cash[0]--;
                cash[1]++;
            }
            if(b==20){
                if(cash[0]==0 and cash[1]==0) return false;
                if(cash[1]>=1 and cash[0]>=1) cash[0]--, cash[1]--;
                else if(cash[0]>=3) cash[0]-=3;
                else return false;
                cash[2]++;
            }
        }
        return true;
    }
};